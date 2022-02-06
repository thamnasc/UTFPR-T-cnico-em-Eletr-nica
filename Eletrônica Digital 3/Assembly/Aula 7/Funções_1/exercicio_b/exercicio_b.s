		AREA ARM, CODE, READONLY
		ENTRY
		LDR R0, =data1
		LDR R1, =fim0
		LDR R2, =data2
		SUB R1, #4
		MOV R3, #0
start	BL ASCII
		BL comp
		BL start
store	STR R3, [R2]
fim		B fim
comp	STMFD sp!, {lr}
		CMP R0, R1
		BLT shift
		B store
ASCII	STMFD sp!, {lr}
load	LDR R4, [R0]
		SUB R4, #0x30
		ADD R3, R4
		LDMFD sp!, {pc}
shift   LSL R3, #4 ;MOVER PARA ESQUERDA PARA JUNTAR
		ADD R0, #4
		LDMFD sp!, {pc}
data1
		DCD 0x35,0x30,0x31,0x32
fim0
		AREA MYDATA, DATA, READWRITE
data2
		END