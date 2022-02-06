		AREA ARM, CODE, READONLY
		ENTRY
		LDR R0, =data1
		LDR R1, =fim0
		LDR R2, [R0]
multi	MOV R3, #3
		MOV R4, R2
op		MUL R4, R2, R4
		SUBS R3, #1
		BNE op
		LDR R5, =data2
		STR R4, [R5]
fim		B fim
data1
		dcd 2
fim0
		AREA MYDATA, DATA, READWRITE
data2	
		END