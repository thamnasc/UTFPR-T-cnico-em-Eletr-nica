		AREA ARM, CODE, READONLY
		ENTRY
start	MOV R0,#0
again	ADD R0,#1
		CMP R0,#59
		BNE again
		B start
		END