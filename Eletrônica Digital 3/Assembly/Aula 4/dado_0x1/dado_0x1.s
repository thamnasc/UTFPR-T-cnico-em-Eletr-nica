		AREA ARM, CODE, READONLY
		ENTRY	
		MOV R0,#0
		LDR R1, =regiao_de_busca
		LDR R2, =0x00000001
		LDR R3, =regiao_fim
compara	LDR R8, [R1]	; mostra no r8 o endereco de r1
		ADD R1, #4		;se nao, procura por mais 4 bits
		CMP R8, R2		;compara regiao de busca com 0x00000001
		BEQ conta		;se for igual, conta
		CMP R1,R3		;compara se nao chegou a regiao_fim
		BNE compara		;se nao, compara
		BEQ fim			;se sim, acaba o codigo
conta	ADD R0,	#1		; registra o numero encontrado igual a 0x00000001
		CMP R1, R3		; compara se nao chegou a regiao_fim
		BNE compara
		BEQ fim			;se sim, acaba o codigo
regiao_de_busca			; dados alocados na memoria
		DCD 1,2,3, 0x12345678, 0x2345, 0x1, 1, 0xfff
		DCD 2, 0xf
		DCD 0
		DCD 2, 4,4,4,4
regiao_fim				;fim do codigo
fim 	B fim
		END
