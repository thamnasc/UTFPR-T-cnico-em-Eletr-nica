/*
Thalita Nascimento
Thiago Saddock*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define setBit(valor, bit) (valor |= (1 << bit))
#define FALL 2
#define RISE 3

void inicializa_USART()
{
	UCSR0A = 0;
	UCSR0B = (1 << RXEN0) + (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) + (1 << UCSZ00);
	UBRR0H = 0;
	UBRR0L = 103;
}

char rxch;

void mensagem(char *message)
{
	int i=0;
	while(*(message+i))
	{
		while((UCSR0A & (1 << UDRE0)) ==0);
		UDR0=*(message+i);
		i++;
	}
	while((UCSR0A & (1 << UDRE0)) ==0);
	UDR0=10;
	while((UCSR0A & (1 << UDRE0)) ==0);
	UDR0=13;
}

int main(void)
{
	DDRD = (1 << FALL) + (1 << RISE);
	char andar = '0', input = '0';
	
	inicializa_USART();
	
	while (1)
	{
		while((UCSR0A & (1 << RXC0))==0);
		rxch = UDR0;
		input = rxch;
		switch (andar)
		{
			case '0':
			if (input=='0')
			{
				mensagem("PARADO");
				mensagem("0");
			}
			else if (input=='1')
			{
				setBit(PORTD,RISE);
				andar = '1';
				mensagem("SUBINDO");
			}
			else
			{
				setBit(PORTD,RISE);
				andar = '2';
				mensagem("SUBINDO");
				_delay_ms(1000);
			}
			break;
			case '1':
			if (input=='0')
			{
				setBit(PORTD,FALL);
				andar = '0';
				mensagem("DESCENDO");
			}
			else if (input=='1')
			{
				mensagem("PARADO");
				mensagem("1");
			}
			else
			{
				setBit(PORTD,RISE);
				andar = '2';
				mensagem("SUBINDO");
			}
			break;
			case '2':
			if (input=='0')
			{
				setBit(PORTD,FALL);
				andar = '0';
				mensagem("DESCENDO");
				_delay_ms(1000);
			}
			else if (input=='1')
			{
				setBit(PORTD,FALL);
				andar = '1';
				mensagem("DESCENDO");
			}
			else
			{
				mensagem("PARADO");
				mensagem("2");
			}
			break;
			default:
			mensagem("PARADO");
			mensagem("0");
			break;
		}
		_delay_ms(1000);
		PORTD = 0;
	}
}


