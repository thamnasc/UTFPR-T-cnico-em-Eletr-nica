		AREA ARM, CODE, READONLY
		ENTRY
		LDR R0, =data1
		LDR R0, [R0]
		MOV R1, #1
		MOV R2, #0
		MOV R3, #0
		BL conta
		LDR R0, =data2
		STR R2, [R0]
fim		B fim
conta	STMFD sp!, {R0, lr}
test	TST R0, R1
		ADD R3, #1
		ADDNE R2, #1
		LSL R1, #1
		CMP R3, #32
		BNE test
		LDMFD sp!, {R0, pc}
data1	dcd 0xFFFF0000 
		AREA MYDATA, DATA, READWRITE
data2
		END