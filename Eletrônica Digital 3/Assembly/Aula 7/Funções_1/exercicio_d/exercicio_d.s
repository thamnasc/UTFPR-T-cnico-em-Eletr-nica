		AREA ARM, CODE, READONLY
		LDR R6, =data1
		LDR R0, [R6]
		LDR R2, [R6, #4]
		MOV R1, #4
		LDR R3, =data
		BL mult
		STR R4, [R3]
fim		B fim
mult	STMFD sp!, {R0, R2, lr}
		MUL R1, R2, R1		;r1=2*4 (8 bits, para saber escolher a posicao)
		MOV R4, #0xF		; posiciona valor F para poder isolar do restante
		LSL R4, R1
		BL isola
		LDMFD sp!, {R0, R2, pc}
isola	STMFD sp!, {lr}
		AND R4, R0			;operação com F 
		LDMFD sp!, {pc}
data1
		dcd 0x0007531
		dcd 0x2
fim1
		AREA MYDATA, DATA, READWRITE
data
		END