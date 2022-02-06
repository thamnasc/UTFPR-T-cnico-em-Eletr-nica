		AREA ARM, CODE, READONLY
		ENTRY
		MOV R0,#0
		MOV R1,#10
volta   ADD R0,R1
		SUBS R1,#1; FLAG ATIVA Z
		BNE volta; enquanto não for zero, volta
fim		B fim
		END