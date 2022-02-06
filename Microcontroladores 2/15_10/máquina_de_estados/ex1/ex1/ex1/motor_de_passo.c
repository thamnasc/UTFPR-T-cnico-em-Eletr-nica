/*
Thalita Nascimento
Thiago Saddock
*/
#define F_CPU 16000000UL 
#include <avr/io.h>
#include <util/delay.h>
#define way 7 //define pino para chave que controla o sentido do motor
#define testBit(valor, bit) (valor & (1 << bit))

int main(void)
{
	
	DDRD = (0 << way);
	DDRB = (1 << PB0) + (1 << PB1) + (1 << PB2) + (1 << PB3); //saidas para o  motor de passo
	PORTD = 0xFF; //habilita pull up
	
	char state = '1'; //variavel para os quatro estados do motor, sendo E1 o primeiro
	
    while (1) 
    {
		switch (state)
		{
			case '1':
				PORTB = 0b00000011;
				if (!(testBit(PIND, way))) //verifica se a chave está zerada, que é o sentido horário
					state = '2';
				else //caso a chave esteja pressionada, o estido é anti-horário
					state = '8';
			break;
			case '2':
				PORTB = 0b00000010;
				if (!(testBit(PIND, way)))
					state = '3';
				else
					state = '1';
			break;
			case '3':
				PORTB = 0b00000110;
				if (!(testBit(PIND, way))) 
					state = '4';
				else 
					state = '2';
			break;
			case '4':
				PORTB = 0b00000100;
				if (!(testBit(PIND, way))) 
					state = '5';
				else 
					state = '3';
			break;
			case '5':
				PORTB = 0b00001100;
				if (!(testBit(PIND, way))) 
					state = '6';
				else 
					state = '4';
			break;
			case '6':
				PORTB = 0b00001000;
				if (!(testBit(PIND, way))) 
					state = '7';
				else 
					state = '5';
			break;
			case '7':
				PORTB = 0b00001001;
				if (!(testBit(PIND, way)))
					state = '8';
				else 
					state = '6';
			break;
			case '8':
				PORTB = 0b00000001;
				if (!(testBit(PIND, way)))
					state = '1';
				else
					state = '7';
			break;
			default:
				state = '1';
				PORTB = 0b00000011;
			break;
		}
		_delay_ms(500);
    }
}

