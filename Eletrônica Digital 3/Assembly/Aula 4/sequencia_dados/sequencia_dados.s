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
		
			LDR R0, =0xFE10F0F0
			LDR R1, =0x00BABACA
			LDR R2, =0x0ABACA7E
			LDR R3, =regiao_de_busca
			LDR R6, =regiao_fim
inicio		LDR R8, [R3]
			ADD R3, #4
			CMP R3,R6
			BEQ fim	
			CMP R8, R0
			BEQ feiofofo
			BNE inicio
feiofofo	LDR R8, [R3]	
			ADD R3, #4
			CMP R3,R6
			BEQ fim				
			CMP R8, R0
			BEQ feiofofo
			CMP R8, R1				
			BNE inicio
			LDR R8, [R3]	
			ADD R3, #4
			CMP R3,R6
			BEQ fim
			CMP R8, R0		
			BEQ feiofofo
			CMP R8, R2
			BNE inicio
			LDR R4, =IO0SET
			STR R5, [R4]
			LDR R4, =IO0CLR
			STR R5, [R4]
			CMP R3,R6
			BNE inicio
			BEQ fim				
regiao_de_busca				
			DCD 1,2,3, 0x12345678, 0x2345, 0x1, 1, 0xfff, 0xFE10F0F0
			DCD 0x00BABACA
			DCD 2, 4,4,4,4,0x0ABACA7E
			DCD 0xFE10F0F0, 0x00BABACA, 0x0ABACA7E
			DCD 2
regiao_fim					
fim			B fim
			END