//---------------------------//
//-- Defini��es principais --//
//---------------------------//


#ifndef _DEF_PRINCIPAIS_H
#define _DEF_PRINCIPAIS_H
#define F_CPU 16000000UL //frequ�ncia de trabalho
#include <avr/io.h> //defini��es do componente especificado
#include <avr/interrupt.h> //define algumas macros para as interrup��es
#include <util/delay.h> //biblioteca para o uso das rotinas de delay
#include <stdlib.h>

//Defini��es de macros para o trabalho com bits
#define setBit(y,bit) (y|=(1<<bit))//coloca em 1 o bit x da vari�vel Y
#define clearBit(y,bit) (y&=~(1<<bit))//coloca em 0 o bit x da vari�vel Y
#define toogleBit(y,bit) (y^=(1<<bit))//troca o estado l�gico do bit x da vari�vel Y
#define testBit(y,bit) (y&(1<<bit))//retorna 0 ou 1 conforme leitura do bit
#endif