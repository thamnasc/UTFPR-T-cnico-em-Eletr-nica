		AREA ARM, CODE, READONLY
		ENTRY
		LDR R0, =regiao_de_busca
		LDR R1, =regiao_fim
		LDR R2, =data2
load	SUB R1, #4
		LDR R8, [R1]
		STR R8, [R2]
		LDR R3, [R2]
		CMP R1, R0
		BEQ fim
		ADD R2, #4
		B load
fim 	B fim		
regiao_de_busca
		dcd 1,2,3, 0x12345678, 0x2345, 0x1, 1, 0xfff
		dcd 2, 0xf
		dcd 0
		dcd 2, 4,4,4,4
regiao_fim
		AREA MyData, DATA, READWRITE
data2 SPACE 255
		END