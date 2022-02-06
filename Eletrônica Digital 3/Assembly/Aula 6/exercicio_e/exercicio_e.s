			AREA ARM, CODE, READONLY
			LDR R0, =data2
			LDR R1, =0xFFFFFFFF
			MOV R2, #1
			MOV R3, #1
			STR R2, [R0]
			STR R3, [R0, #4]
soma		ADDS R3, R2, R3
			BVS fim
			STR R3, [R0, #8]
			ADD R0, #4
			LDR R2, [R0]
			B soma
fim 		B fim			
			AREA MYDATA, DATA, READWRITE	
data2
			END