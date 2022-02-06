		AREA ARM, CODE, READONLY
		ENTRY
		LDR R0, =data1
		LDR R1, =data
		LDR R2, =0xFFFFFFFF
		MOV R3, #0xF
		MOV R4, #0xF0000000
		LDR R6, [R0]
		BL setM
fim		B fim
setM    STMFD sp!, {R6, lr}
		BIC R6, R3
		BL setL
		LDMFD sp!, {R6, pc}
setL    STMFD sp!, {R6, lr}
		BIC R6, R4
		STR R6, [R1]
		LDMFD sp!, {R6, pc}
data1
		dcd	0x8ABCDEF9
fim1
		AREA MYDATA, DATA, READWRITE
data
		END