		AREA ARM, CODE, READONLY
		ENTRY
IO0PIN EQU 0xE0028000
IO0SET EQU 0xE0028004
IO0DIR EQU 0xE0028008
IO0CLR EQU 0xE002800C
IO1PIN EQU 0xE0028010
IO1DIR EQU 0xE0028018
	
		LDR R4, =IO0DIR
		LDR R5, =0xFFFFFFFF;leds contador saida
		STR R5, [R4]
		
		LDR R4, =IO1DIR
		LDR R5, =0xFFFEFFFF;chave entrada
		STR R5, [R4]
				
RESTART	MOV R0, #0
		LDR R4, =IO0PIN;armazena 0 no pino de saida
		STR R0, [R4]
VERF	LDR R4, =IO1PIN;verifica chave
		LDR R5,[R4]
		TST R5, #0X00010000
		BEQ VERF
CONTA	ADD R0, #1
		CMP R0, #60
		BEQ RESTART;quando chega a 60 nao salva na saida, recomeca
		LDR R4, =IO0PIN; menor que 60 é armazenado na saida
		STR R0, [R4]
		B VERF;verifica a chave para poder adicionar novamente
		END

