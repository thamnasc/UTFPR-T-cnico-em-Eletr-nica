		AREA ARM, CODE, READONLY
		ENTRY
		LDR R1, =data
		LDR R6, =data1
		LDR R7, =fim1
		LDR R0, [R6]
		BL seta
		LDR R0, [R1]
		BL apaga
fim		B fim
seta	STMFD sp!, {R0, lr}
		MOV R8, R0
		AND R8, #0x0FFFFFFF			;zera MSByte para poder somar F
		LDR R2, =0xF0000000
		ADD R8, R2
		STR R8, [R1]
		LDMFD sp!, {R0, pc}
apaga	STMFD sp!, {R0, lr}
		MOV R8, R0
		AND R8, #0xFFFFFFF0				; zera LSByte
		STR R8, [R1]
		LDMFD sp!, {R0, pc}
data1
		dcd 0x8ABCDEF9
fim1
		AREA MYDATA, DATA, READWRITE
data
		END