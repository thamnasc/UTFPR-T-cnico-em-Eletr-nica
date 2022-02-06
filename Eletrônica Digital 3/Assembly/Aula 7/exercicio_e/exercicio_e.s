		AREA ARM, CODE, READONLY
		LDR R8, =data1
		LDR R0, [R8]				;numero
		LDR R1, [R8]				;posição 1 (setar)
		LDR R2, [R8]				;posição 2 (resetar)
		LDR R3, [R8]				;posição 3 (inverter)
		MOV R4, #0xF
		LDR R5, =0xFFFFFFFF
		BL set
		STR R2, [R1]
fim		B fim
num		STMFD sp!, {R0-R3, lr}
		MOV R5, #4
		LDR R4, [R0,#4]!
		MUL R5, R4, R5
		LSL R3, R5
		MOV R7, R3
		LDMFD sp!, {R0-R3, pc}
set		STMFD sp!, {R0, lr}
		LDR R1, [R0,#4]
		LSL R4, R1
		SUB R5, R4
		LDMFD sp!, {R0-R3, pc}
reset	STMFD sp!, {R0-R3, lr}
		SUB R6, R7
		AND R2, R6
		LDMFD sp!, {R6, pc}
not 	STMFD sp!, {R6, lr}
		EOR R0, R7
		LDMFD sp!, {R0-R3, pc}
data1
		dcd 0xE90C234
		dcd 0x6, 0x0, 0x3
fim1
		AREA MYDATA, DATA, READWRITE
data
		END