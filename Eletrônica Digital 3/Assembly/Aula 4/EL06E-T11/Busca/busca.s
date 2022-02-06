		AREA ARM_data, CODE, READONLY
		ENTRY
		
IO0DIR	EQU 0xE0028008
IO0PIN 	EQU 0xE0028000
IO0SET 	EQU 0xE0028004
IO0CLR 	EQU 0xE002800C

		
		LDR R9, =IO0DIR
		LDR R8, =0xFFFFFFFF
		STR R8, [R9]
		LDR R7, =IO0PIN
		LDR R6, =0x00000001
		LDR R5, =0x00000000
		LDR R4, =0xFE10F0F0
		
		LDR R0, =area_busca
		LDR R1, =busca_fim
volta	LDR R3, [R0]
		CMP R3, R4
		BNE bisca
		STR R6, [R7]
bisca	STR R5, [R7]
		CMP R0, R1
		ADD R0, #4
		BNE volta
fim		B fim

area_busca
		DCD 1, 2, 3, 0x12345678, 0x2345, 0x1, 1, 0xfff
		DCD 2, 0xf
		DCD 0, 0XFE10F0F0
		DCD 2, 4,4,4,4
busca_fim
		END