/*
Thalita Nascimento
 Thiago Saddock
 */ 

#define F_CPU 16000000L
#define F_SCL 100000L

#include <avr/io.h>
#include <util/delay.h>

#define SDA DDC4
#define SCL DDC5
#define TWI_START (1<<TWINT)+(1<<TWSTA)+(1<<TWEN)
#define TWI_STOP (1<<TWINT)+(1<<TWSTO)+(1<<TWEN)
#define TWI_ACK (1<<TWINT)+(1<<TWEA)+(1<<TWEN)
#define TWI_NACK (1<<TWINT)+(1<<TWEN)
#define TWI_SEND (1<<TWINT)+(1<<TWEN)
#define TWI_RDY (TWCR & (1<<TWINT))
#define TWI_STATUS (TWSR & 0xF8)
#define START_ANSW 0x08
#define MT_SLA_ACK 0x18
#define MT_DATA_ACK 0x28
#define TW_REP_START 0x10
#define TWI_READ 1
#define TWI_WRITE 0
#define testBit(valor,bit) (valor & (1<<bit))

uint8_t j = 1, i = 0, a, dado = 0x01;

void twi_init()
{
    TWSR = 0;
    TWBR = ((F_CPU/F_SCL)-16)/2; // define a frequencia do TWI
}

uint8_t twi_start()
{
    TWCR = TWI_START;
    while(!TWI_RDY);
    if(TWI_STATUS != START_ANSW)
        return 1;
    return 0;
}

void twi_stop()
{
    TWCR = TWI_STOP;
    while(TWCR & (1<<TWSTO));
}

uint8_t twi_slaveaddr(uint8_t addr, uint8_t rw)
// addr = endereco do dispositivo slave
// rw = operacao: 0=escrita, 1=leitura
{
    TWDR = (addr<<1)+rw;
    TWCR = TWI_SEND;
    while(!TWI_RDY);
    if(TWI_STATUS != MT_SLA_ACK)
        return 1;
    return 0;
}

uint8_t twisendData(uint8_t dado)
{
    TWDR = dado;
    TWCR = TWI_SEND;
    while(!TWI_RDY);
    if(TWI_STATUS != MT_DATA_ACK)
        return 1;
    return 0;
}

uint8_t twi_getNack()
{
    TWCR = TWI_NACK;
    while(!TWI_RDY);
    return TWDR;
}

void configTWI ()
{
	twi_start();
	twi_slaveaddr(0x20, TWI_WRITE);
	twisendData(~dado);
	twi_stop();
}

void LEDtroca ()
{
	//if (!(PORTB & (1<<PINB0))) //define meio como LED 5
	if (testBit(PINB, 0)) //define meio como LED 5
	{
		_delay_ms(10); //debounce
		
		dado = j;
		
		j = 0xFF;
		
		configTWI();
		
		_delay_ms(3000); //tempo em que todos os LEDs ficam ligados
		
		j = 0x00;
		
		configTWI();
	}
}

int main(void)
{
	DDRB = 0x00;
	PORTB = 0xFF; //habilita pull up 
    DDRC = (1<<SDA) + (1<<SCL);
	
    twi_init();
	
    while (1)
    {
		i = 0;
		
		for(i;i<8;i++)
		{
			dado = j;
			
			configTWI();

			j =~ (1<<i);
			
			if(i==4)
				LEDtroca();
		
			_delay_ms(500);
		}
	
		i = 8;
	
		for(i;i>0;i--)
		{
			a = i-1;
			
			dado = j;
			
			configTWI();
			
			j =~ (1<<a);
		
			if(i==5)
				LEDtroca();
			
			_delay_ms(500);
		}
		
    }
}