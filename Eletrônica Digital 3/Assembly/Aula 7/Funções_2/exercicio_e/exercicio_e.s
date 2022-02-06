			AREA ARM, CODE, READONLY
			ENTRY
			LDR R0, =data1
			BL bcd
			LDR R1, =data
			STR R0, [R1]
bcd			STMFD sp!, {lr}
			LDR R2, [R0]
			LDMFD sp!, {pc}
data1 		dcd 0x123
fim1
			AREA MYDATA, DATA, READWRITE
data
			END