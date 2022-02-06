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
#define ativa_SS() (PORTB &= ~(1<<SS))
//#define testa_botao1() (PIND & (1<<DIR))
//#define testa_botao2() (PIND & (1<<VEL))#define toogleBit(valor,bit) (valor ^= (1 << bit))uint8_t dado=0b00000001;void spi_init()
{
	DDRSPI = (1<<MOSI) + (1<<SCK) + (1<<SS); //define pinos MOSI, SCK e SS como
	// saida
	SPCR = (1<<SPE) + (1<<MSTR) + (1<<SPR0); // Habilita interface SPI como
	// MASTER e define clock como fosc/16
}

uint8_t spi_txrx(uint8_t data)
{
	SPDR = data; // inicia a transmissao
	while(!(SPSR & (1<<SPIF))); // espera a transmissao terminar
	return SPDR; // retorna o dado recebido
}

int main()
{
	DDRD=0x0;
	PORTD=0xFF;
	
	spi_init();
	
	while(1)
	{
		if (!toogleBit(PORTD,VEL))
			SPCR = (0<<SPI2X); // inicializa interface SPI para velocidade normal
		
		else
			SPCR = (1<<SPI2X); // inicializa interface SPI para dupla velocidade
		
		if (!toogleBit(PORTD,DIR))
		{
			if (dado == 0x1)
			dado = 0b10000000;
			
			dado = (1 << dado);
			
			ativa_SS(); // ativa SS para avisar o SLAVE que havera uma
			// comunicacao
			spi_txrx(dado); // envia estado do botao para o SLAVE e recebe
			// o estado do botao do SLAVE
			desativa_SS(); // desatica SS para indicar que a comunicacao
		}
		
		else
		{
			if (dado == 0b10000000)
			dado = 0x1;
			
			dado = (1 >> dado);
			
			ativa_SS(); // ativa SS para avisar o SLAVE que havera uma
			// comunicacao
			spi_txrx(dado); // envia estado do botao para o SLAVE e recebe
			// o estado do botao do SLAVE
			desativa_SS(); // desatica SS para indicar que a comunicacao
		}	
			
		_delay_ms(500);
	}
}


