	AREA ARM, CODE, READONLY
	ENTRY
IO1PIN EQU 0xE0028010
IO1DIR EQU 0xE0028018
IO0PIN EQU 0xE0028000
IO0SET EQU 0xE0028004
IO0CLR EQU 0xE002800C
IO0DIR EQU 0xE0028008
	
		LDR R4, =IO0DIR
		LDR R5, =0xFFFFFFFF; chave de habilitacao e LEDS
		STR R5, [R4]
		
		LDR R4, =IO1DIR
		LDR R5, =0xFFFEFFFF;chave como clk para contar
		STR R5, [R4]
		
RESTART			MOV R0, #0;começa com zero
				LDR R4, =IO0PIN
				STR R0, [R4];salva zero na memoria
DESCIDA			LDR R4, =IO1PIN;verifica se está no nivel alto
				LDR R5, [R4]
				TST R5, #0x00010000
				BNE DESCIDA ;de 1 vai para 0(rampa de descida)
				CMP R0, #59;compara se o registrador nao está com valor 59
				BEQ RESTART
				ADD R0, #1;soma para contar
SUBIDA			LDR R4, =IO1PIN;verifica se está na rampa de descida
				LDR R5, [R4]
				TST R5, #0x00010000
				BEQ SUBIDA; de 0 vai para 1(rampa de subida)
				LDR R4, =IO0PIN;armazena no pino da saida a contagem
				STR R0, [R4]
				B DESCIDA;volta a contar verificando se está em nivel alto 
				END
				