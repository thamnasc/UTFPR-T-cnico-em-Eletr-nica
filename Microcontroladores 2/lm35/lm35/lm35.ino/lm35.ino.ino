
/*
 Author : Thalita && Thiago
 */ 

#include "LCD.h" // Biblioteca com as funções do LCD
#include "def.h" // Biblioteca com definições básicas
#define INC 2
#define DEC 3
#define SET 4
#define LED 5

void inicializa_ADC()
{
  ADMUX = (0<<REFS1) + (1<<REFS0) // Seleciona Vref de 1.1V
      + (0<<MUX0); // Seleciona ADC0
  ADCSRA = (1<<ADEN) // habilita ADC
      + (1<<ADPS2); // seleciona clock como fosc/16
}


int main(void)
{
  DDRD=(0<<INC)+(0<<DEC)+(0<<SET)+(1<<LED);
  PORTD=(1<<INC)+(1<<DEC)+(1<<SET);
  DDRC=(0<<PC0);
  PORTC=(1<<PC0);
  
  int temp, resultadoADC, danger = 50, novo = 50, c = 1;
  char str[10];
  
  inicializa_ADC();
  
  lcd_D7_ddr |= (1<<lcd_D7_bit);                  // 4 data lines - output
  lcd_D6_ddr |= (1<<lcd_D6_bit);
  lcd_D5_ddr |= (1<<lcd_D5_bit);
  lcd_D4_ddr |= (1<<lcd_D4_bit);
  lcd_E_ddr |= (1<<lcd_E_bit);                    // E line - output
  lcd_RS_ddr |= (1<<lcd_RS_bit);                  // RS line - output
    lcd_init_4d();                  //inicializa o lcd
  
  
    while (1) 
    { 
    if(!(PIND & (1 << PIND2))) //botao de incremento
    {
      _delay_ms(10); //debounce
      novo++;
      c=0; //variavel de controle, c=1 muda a string para "alarme"
    }
    if(!(PIND & (1 << PIND3))) //botao de decremento
    {
      _delay_ms(10);
      novo--;
      c=0; //mantem a string como "novo", para visualizacao do manuseio dos botoes
    }
    if(!(PIND & (1 << PIND4))) //botao de set
    {
      _delay_ms(10);
      danger = novo; //o valor de novo e atribuido para a temperatura de alarme
      c=1;
    }

    ADCSRA |= (1<<ADSC) + (1<<ADEN); // pulso de disparo da conversao
    _delay_us(100); //espera pela estabilização de Vin
    while((ADCSRA & (1<<ADIF))==0); // espera conversao terminar
    ADCSRA |= (1<<ADIF); // reseta flag de fim de conversao
    ADCSRA &= ~(1<<ADEN);
    resultadoADC = ADCW; // obtem o valor convertido (ADCH:ADCL)
    temp = resultadoADC*5*100L/1024; //Define o tempo em alto de acordo com a entrada analogica
    //o L serve para tornar o int como long
    //como a alimentacao e de 5V, impacta no referencial do ADC
    //100 corresponde ao valor de mV por graus celsius, que e 10mV
    //ha a divisao por 1024 devido ao pino analogico do arduino, que
      //converte a entrada para ate 2^10 

    itoa(temp,str,10);
    lcd_write_string_4d(str); //funcao de escrita
    lcd_write_string_4d(" graus"); //funcao de escrita
    lcd_write_instruction_4d(lcd_SetCursor | lcd_LineTwo); //seta o cursor para a linha debaixo
    _delay_us(80);
    if(c==1) //laco de alarme
    {
      lcd_write_string_4d("Alarme "); //funcao de escrita
      itoa(danger,str,10); //danger e a temperatura de alarme
    }

    if(c==0) //laco de mudanca de alarme
    {
      lcd_write_string_4d("Novo "); //funcao de escrita
      itoa(novo,str,10); 
    }
    lcd_write_string_4d(str); //funcao de escrita
    lcd_write_string_4d(" graus"); //funcao de escrita
    _delay_ms(500);
    lcd_write_instruction_4d(lcd_Clear); //funcao de "limpar" a tela
    _delay_ms(4);
    
    if(danger<temp||danger==temp) //se o valor da temperatura e igual ou excede o alarme
      setBit(PORTD,5); //o LED e setado
    else
      clearBit(PORTD,5); //caso seja menor, recebe clear
  }
    
}

