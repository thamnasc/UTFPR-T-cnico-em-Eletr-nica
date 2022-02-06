		AREA ARMex, CODE, READONLY
		ENTRY
		MOV R1, #0
		MOV R2, #10
again	ADDS R1,R1,#1
		CMP R2,R1
		BNE again
halt	B halt
		END