		AREA ARM, CODE, READONLY
		LDR R0, =data1
		LDR R1, =fim0
		LDR R2, =data2
		LDR R2, [R0]
		MOV R3, #3			
		MOV R4, R2
op		MUL R4, R2, R4			;resulta em X10
		SUBS R3, #1
		BGT op
		MOV R5, #3
		MUL R5, R4, R5			;resulta em X30; CONTA 3x^4
		MOV R6, #2				
		MUL R6, R2, R6			;resulta em X4;	 CONTA 2x
		SUB R5, R6				;resulta em X2B	 CONTA 3x^4-2x				
		MOV R6, #7				;resulta em X7
		ADD R5, R6				;resulta em X33	 CONTA anterior somada de 7
		LDR R7, =data2
		STR R5, [R7]
fim 	B fim
data1
		dcd 1
fim0
		AREA MYDATA, DATA, READWRITE
data2
		END