		AREA ARMex, CODE, READONLY
		ENTRY
		MOV R1, #10
again	SUBS R1,R1,#1
		BNE again
halt 	B halt
		END