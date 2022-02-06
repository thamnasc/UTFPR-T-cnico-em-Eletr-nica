			AREA ARM, CODE, READONLY
			ENTRY
			LDR R0, =data1
			LDR R1, =fim0
			LDR R2, [R0]
			MOV R3, R2
mult		SUBS R2, #1
			BEQ grava
			MUL R3, R2, R3
			B mult
grava		LDR R4, =data2
			STR R3, [R4]
fim			B fim
data1
			dcd 4
fim0
			AREA MYDATA, DATA, READWRITE
data2
			END