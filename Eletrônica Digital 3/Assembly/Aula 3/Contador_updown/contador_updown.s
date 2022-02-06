	AREA ARM, CODE, READONLY
	ENTRY
IO1PIN EQU 0xE0028010
IO1DIR EQU 0xE0028018
IO0PIN EQU 0xE0028000
IO0SET EQU 0xE0028004
IO0CLR EQU 0xE002800C
IO0DIR EQU 0xE0028008
		
			LDR R4, =IO0DIR
			LDR R5, =0xFFFFFFFF; saida LEDs
			STR R5, [R4]
			
			LDR R4, =IO1DIR
			LDR R5, =0xFFFEFFFF; habilitacao e chave sentido 
			STR R5, [R4]
			MOV R0, #0
			
TEST		  LDR R4, =IO1PIN; verifica chave que dita o sentido
			  LDR R5, [R4]
			  LDR R4, =IO0PIN; load na saida
			  TST R5, #0x00010000
			  BEQ DECRESC; se for igual, conta decrescente
CRESC		  ADD R0, #1
			  STR R0, [R4]
			  CMP R0, #9
			  BNE TEST
			  MOV R0, #0
			  STR R0, [R4]
			  B TEST
DECRESC 	  SUB R0, #1
			  STR R0, [R4]
			  CMP R0, #0
			  BNE TEST
			  MOV R0, #10
			  B TEST
			  END
			  