			AREA ARM, CODE, READONLY
			MOV R0, #0
			MOV R1, #10
continua	ADD R0, R1
			SUBS R1, #1
			BNE continua
			LDR R2, =data2
			STR R0, [R2]
fim 		B fim
		AREA MYDATA, DATA, READWRITE
data2	
		END