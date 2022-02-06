/*
  WriteMultipleFields
  
  Description: Writes values to fields 1,2,3,4 and status in a single ThingSpeak update every 20 seconds.
  
  Hardware: ESP32 based boards
  
  !!! IMPORTANT - Modify the secrets.h file for this project with your network connection and ThingSpeak channel details. !!!
  
  Note:
  - Requires installation of EPS32 core. See https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md for details. 
  - Select the target hardware from the Tools->Board menu
  - This example is written for a network using WPA encryption. For WEP or WPA, change the WiFi.begin() call accordingly.
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize, and 
  analyze live data streams in the cloud. Visit https://www.thingspeak.com to sign up for a free account and create a channel.  
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the README.md folder where the library was installed.
  See https://www.mathworks.com/help/thingspeak/index.html for the full ThingSpeak documentation.
  
  For licensing information, see the accompanying license file.
  
  Copyright 2018, The MathWorks, Inc.
*/

/*Thalita Nascimento
  Thiago Saddock
 */

#include "ThingSpeak.h"
#include "secrets.h"
#include <WiFi.h>
#include <PubSubClient.h>

char ssid[] = "Roma";   // your network SSID (name) 
char pass[] = "84127544";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
const char* BROKER_MQTT = "mqtt.eclipse.org"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 1883;                      // Porta do Broker MQTT

//defines de id mqtt e tópicos para publicação e subscribe
#define TOPICO_SUBSCRIBE "MQTTFFThalitaThiagoEnvia"     //tópico MQTT de escuta
#define ID_MQTT  "TempThalitaThiago"     //id mqtt (para identificação de sessão)

WiFiClient  client;
WiFiClient  clientMQTT;
PubSubClient MQTT(clientMQTT); // Instancia o Cliente MQTT passando o objeto clientMQTT
  
unsigned long myChannelNumber = 915584;
const char * myWriteAPIKey = "XQXDHFEETIKTWEHT";

String myStatus = "";

//temperatua atual e anterior
int temp,temp_st=0;

void initWiFi();
void initMQTT();


//configuracao de setup
void setup() {
  Serial.begin(115200);  //Initialize serial

  WiFi.mode(WIFI_STA); 
  initWiFi();  
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

//inicializacao de WiFi
void initWiFi()
{
 // Connect or reconnect to WiFi
   if(WiFi.status() != WL_CONNECTED)
   {
     Serial.print("Attempting to connect to SSID: ");
     Serial.println(ssid);
     while(WiFi.status() != WL_CONNECTED)
     {
       WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
       Serial.print(".");
       delay(5000);     
     } 
     Serial.println("\nConnected.");
   }
}

//inicializacao de MQTT
void initMQTT() 
{
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);   //informa qual broker e porta deve ser conectado
    while (!MQTT.connect(ID_MQTT)) 
    {
        Serial.print("* Tentando se conectar ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT)) 
        {
            Serial.println("Conectado com sucesso ao broker MQTT!");
            MQTT.subscribe(TOPICO_SUBSCRIBE); 
        } 
        else
        {
            Serial.println("Falha ao reconectar no broker.");
            Serial.println("Havera nova tentatica de conexao em 2s");
            delay(2000);
        }
    }
}

void loop() 
{
  
//inicializa conexoes
  initWiFi();
  initMQTT();

//calculo da entrada analogica
  temp_st = temp; //temperatura de comparacao (coletada anteriormente)
  temp = (analogRead(A0) / 2048.0) * 3300; //3.3*1L*100/4095, sendo 3.3V a referencia, 100 devido a 10mV/C e 4095 porque a entrada adc do esp32 tem 2^12 bits
  temp = temp * 0.1;
  //GPIO 36 == A0
  Serial.print(temp);
  Serial.print("\n");

//configuracao dos fields do grafico
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, temp_st);
  
// figure out the status message
  if(temp > temp_st)
    myStatus = String("field1 is greater than field2"); 
  else if(temp < temp_st)
    myStatus = String("field1 is less than field2");
  else
    myStatus = String("field1 equals field2");
  
// set the status
  ThingSpeak.setStatus(myStatus);
  
// write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200)
    Serial.println("Channel update successful.");
  else
    Serial.println("Problem updating channel. HTTP error code " + String(x));

//Envio de dados para o MQTT
  char MsgTempMQTT[50];
  
  if (x == 200)
  {
      sprintf(MsgTempMQTT,"- Temperatura do Ambiente: %d ºC.",temp);
      MQTT.publish(TOPICO_SUBSCRIBE, MsgTempMQTT);
  }
 
  delay(60000); //intervalo de um minuto para se enviar dados
}
