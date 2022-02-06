/*
Thalita Nascimento
Thiago Saddock*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define setBit(valor, bit) (valor |= (1 << bit))
#define FALL 2
#define RISE 3

int main(void)
{
	DDRD = (1 << FALL) + (1 << RISE);
	char floor = 'T', input = 'T';
	
	
    while (1) 
    {
		switch (floor)
		{
			case 'T':
				if (input=='T')
				{
					
				}	
				else if (input=='1')
				{
					setBit(PORTD,RISE);
					floor = '1';
				}
				else
				{
					setBit(PORTD,RISE);
					floor = '2';
					_delay_ms(1000);
				}
			break;
			case '1':
				if (input=='T')
				{
					setBit(PORTD,FALL);
					floor = 'T';
				}
				else if (input=='1')
				{
					
				}
				else
				{
					setBit(PORTD,RISE);
					floor = '2';
				}
			break;
			case '2':
				if (input=='T')
				{
					setBit(PORTD,FALL);
					floor = 'T';
					_delay_ms(1000);
				}
				else if (input=='1')
				{
					setBit(PORTD,FALL);
					floor = '1';
				}
				else
				{
					
				}
			break;
			default:
				
			break;
		}
		_delay_ms(1000);
    }
}

