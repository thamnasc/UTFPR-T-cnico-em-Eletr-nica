		AREA ARM, CODE, READONLY
		LDR R8, =data1
		LDR R9, =data
		LDR R0, [R8]				;numero
		MOV R2, #0xF
		LDR R3, =0xFFFFFFFF
		LDR R4, [R8, #4]
		LDR R5, [R8, #8]
		LDR R6, [R8, #12]
		MOV R1, #4
		BL num
		STR R7, [R9]
fim		B fim
num		STMFD sp!, {R0,R4-R6, lr}
		MUL R4, R1, R4
		LSL R4, R2, R4
		MUL R5, R1, R5
		LSL R5, R2, R5
		MUL R6, R1, R6
		LSL R6, R2, R6
		BL set
		BL reset
		BL not
		LDMFD sp!, {R0,R4-R6, pc}
set		STMFD sp!, {R0,R4-R6, lr}
		BIC R0, R4
		ADD R7, R0, R4
		LDMFD sp!, {R0,R4-R6, pc}
reset	STMFD sp!, {R0,R4-R6, lr}
		BIC R7, R5
		LDMFD sp!, {R0,R4-R6, pc}
not 	STMFD sp!, {R0,R4-R6, lr}
		EOR R7, R6
		LDMFD sp!, {R0,R4-R6, pc}
data1
		dcd 0xE90C234
		dcd 0x6, 0x0, 0x3
fim1
		AREA MYDATA, DATA, READWRITE
data
		END