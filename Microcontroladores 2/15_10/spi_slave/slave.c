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
#define desativa_SS() (PORTB |= (1<<SS))
#define ativa_SS() (PORTB &= ~(1<<DDB2))
#define testa_SS() (PORTB & (1<<DDB2))

uint8_t dado;

void spi_init()
{
//	DDRSPI = (1<<MISO); // define pino MISO como saida
	SPCR = (1<<SPE); // Habilita interface SPI como SLAVE
}

uint8_t spi_txrx()
{
	uint8_t data;
	data = SPDR; // inicia a transmissao
	while(!(SPSR & (1<<SPIF))); // espera a transmissao terminar
	return data; // retorna o dado recebido
}

int main()
{
	DDRD=0xFF; 
	DDRB=0x00;
	DDRB=0xFF;
	
	spi_init(); // inicializa interface SPI
	
	while(1)
	{
		ativa_SS(); // ativa SS para avisar o SLAVE que havera uma
		// comunicacao
		dado=spi_txrx(); // envia estado do botao para o SLAVE e recebe
		// o estado do botao do SLAVE
		desativa_SS(); // desatica SS para indicar que a comunicacao
		// acabou
		
		PORTD = dado;
	}
}
