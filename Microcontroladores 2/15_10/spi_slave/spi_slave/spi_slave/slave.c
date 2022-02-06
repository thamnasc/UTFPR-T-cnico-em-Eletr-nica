/*Thalita Nascimento
Thiago Saddock
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define DDRSPI DDRB
#define SCK DDB5
#define MOSI DDB3
#define SS DDB2

uint8_t dado;

void spi_init()
{
	SPCR = (1<<SPE); // Habilita interface SPI como SLAVE
}

uint8_t spi_txrx()
{
	while(!(SPSR & (1<<SPIF))); // espera a transmissao terminar
	return SPDR; // retorna o dado recebido
}

int main()
{
	DDRD=0xFF;
	DDRB=0x00;
	PORTB=0xFF; //habilita os pull ups
	UCSR0B=0x00; //configura para utilizar pinos PD0 e PD1
	
	spi_init(); // inicializa interface SPI
	
	while(1)
	{
		dado=spi_txrx(); // variavel recebe dado do SPDR
		PORTD = dado; //PORTD recebe o valor enviado pelo master
	}
}
