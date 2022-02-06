/*Thalita Nascimento
Thiago Saddock*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define DDRSPI DDRB
#define SCK DDB5
#define MOSI DDB3
#define SS DDB2
#define DIR DDD2
#define VEL DDD3
#define desativa_SS() (PORTB |= (1<<SS))
#define ativa_SS() (PORTB &= ~(1<<SS))void spi_init()
{
	DDRSPI = (1<<MOSI) + (1<<SCK) + (1<<SS); //define pinos MOSI, SCK e SS como saida
	SPCR = (1<<SPE) + (1<<MSTR) + (1<<SPR0); // Habilita interface SPI como master e clock fosc/16
}

uint8_t spi_txrx(uint8_t data)
{
	SPDR = data; // inicia a transmissao
	while(!(SPSR & (1<<SPIF))); // espera a transmissao terminar
}

int main()
{
	DDRD=0x0;
	PORTD=0xFF; //habilita pull ups
	uint8_t dado=0b00000001; //inicia setando led 0
	
	spi_init(); //chama a funcao de inicializacao
	
	while(1)
	{
		if (PIND & (1<<VEL))
		{
			_delay_ms(10); //debounce
			SPCR |= (1<<SPI2X); // inicializa interface SPI para velocidade normal
		}
			
		else
		{
			_delay_ms(10); //debounce
			SPCR &=~ (1<<SPI2X); // inicializa interface SPI para dupla velocidade
		}
			
		if (PIND & (1<<DIR))
		{
			_delay_ms(10); //debounce
			
			ativa_SS(); // ativa SS para avisar o SLAVE que havera comunicacao
			spi_txrx(dado); // registrador SPDR recebe dado a ser envia ao slave
			desativa_SS(); // desatica SS para indicar que a comunicacao acabou
			
			dado = dado << 1; //desloca o bit, acendendo o proximo led
			
			if (dado ==  0x00) //caso chegue no oitavo led da direcao escolhida, volta ao inicio
				dado = 0b00000001;
		}
		
		else
		{
			_delay_ms(10); //debounce
					
			ativa_SS(); // ativa SS para avisar o SLAVE que havera comunicacao
			spi_txrx(dado); // registrador SPDR recebe dado a ser envia ao slave
			desativa_SS(); // desatica SS para indicar que a comunicacao acabou
			
			dado = dado >> 1; //desloca o bit, acendendo o proximo led
			
			if (dado == 0b00000000) //caso chegue no oitavo led da direcao escolhida, volta ao inicio
				dado =  0b10000000;
		}
		
		_delay_ms(250);
	}
}


