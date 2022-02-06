		AREA RESET, CODE, READONLY
		ENTRY
		
IO0DIR EQU 0xE0028008
IO0PIN EQU 0xE0028000
IO0SET EQU 0xE0028004
IO0CLR EQU 0xE002800C

		ldr r4, =IO0DIR
		ldr r5, =0x000F0000
		str r5, [r4]
		
Pisca	ldr r4, =IO0SET
		ldr r5, =0x000F0000
		str r5, [r4]
		
		ldr r4, =IO0CLR
		ldr r5, =0x000F0000
		str r5, [r4]
		B Pisca
		END