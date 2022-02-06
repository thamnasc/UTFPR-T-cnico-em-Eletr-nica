		AREA ARM, CODE, READONLY
		ENTRY		
IO0PIN 	EQU 0xE0028000
IO0SET 	EQU 0xE0028004
IO0DIR 	EQU 0xE0028008
IO0CLR 	EQU 0xE002800C
IO1PIN 	EQU 0xE0028010
IO1DIR 	EQU 0xE0028018
	
		LDR R4, =IO0DIR
		LDR R5, =0xFFFFFFFF
		STR R5, [R4]
		
START	LDR R2, =regiao_de_busca
		LDR R3, =0xFE10F0F0
		LDR R6, =regiao_fim
repete	LDR R8,[R2] 	;mostra no r8 os dados da memoria de r2
		CMP R8, R3		;compara regiao_de_busca com feiofofo
		ADD R2, #4		;se nao, procura por mais 4 bits
		BEQ liga		;se for igual, liga o LED
		CMP R2, R6
		BEQ FIM
		BNE repete		;se nao, compara de novo
liga	LDR R4, =IO0SET
		STR R5, [R4]
		LDR R4, =IO0CLR
		STR R5, [R4]
		B repete
regiao_de_busca
		DCD 1,2,3,0x12345678,0x2345,0x1,1,0xFE10F0F0,4
regiao_fim
FIM		B FIM
		END