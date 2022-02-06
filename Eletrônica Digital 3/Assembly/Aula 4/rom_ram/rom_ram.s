		AREA ARM, CODE, READONLY
		ENTRY
		LDR R0, =regiao_de_busca
		LDR R1, =regiao_fim
		LDR R2, =data2
load	LDR R8, [R0]
		CMP R0, R1
		BEQ fim
		STR R8, [R2]
		ADD R0, #4
		ADD R2, #4
		B load
fim     B fim
regiao_de_busca
		dcd 1,2,3, 0x12345678, 0x2345, 0x1, 1, 0xfff
		dcd 2, 0xf
		dcd 0
		dcd 2, 4,4,4,4
regiao_fim
		AREA MyData, DATA, READWRITE
data2 SPACE 255
		END