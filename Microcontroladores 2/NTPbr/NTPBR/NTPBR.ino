#include <NTPClient.h>//Biblioteca do NTP.
#include <WiFiUDP.h>//Biblioteca do UDP.
#include <WiFi.h>//Biblioteca do WiFi.

WiFiUDP udp;//Cria um objeto "UDP", de acordo com o fuso 0.
WiFiUDP udpbr;//Cria um objeto "UDP", de acordo com o fuso -3.
NTPClient ntp(udp, "a.st1.ntp.br", 0, 60000);//Cria um objeto "NTP" com as configurações.
NTPClient ntpbr(udpbr, "a.st1.ntp.br", -3 * 3600, 60000);
//#define led D2//Define o LED ao pino D2.

String hora, horabr;//Váriavel que armazenara o horario do NTP.

void setup()
{
   Serial.begin(9600);//Inicia a comunicação serial.

   /*pinMode(led, OUTPUT);//Define o pino como saida.
   digitalWrite(led, 1);//Apaga o LED.*/

   WiFi.mode(WIFI_STA);
   WiFi.begin("Yamineko", "kuroneko");//Conecta ao WiFi.
   delay(2000);//Espera a conexão.

   ntp.begin();//Inicia o NTP.
   ntpbr.begin();
   ntp.forceUpdate();//Força o Update.
   ntpbr.forceUpadate();
}

void loop()
{
   hora = ntp.getFormattedTime();//Armazena na váriavel HORA, o horario atual.
   horabr = ntpbr.getFormattedTime();
   Serial.println("HORA UNIVERSAL");
   Serial.println(hora);//Printa a hora já formatada no monitor.
   Serial.println("HORA BRASILEIRA");
   Serial.println(horabr);

   delay(1000);//Espera 1 segundo.
}
