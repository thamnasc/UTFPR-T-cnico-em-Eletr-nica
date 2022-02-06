		AREA ARM, CODE, READONLY
		ENTRY
    	MOV R0,#0
volta	ADD R0, #1
		CMP R0, #6
		BNE volta
fim		B fim
		END