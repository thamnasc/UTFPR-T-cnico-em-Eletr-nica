		AREA ARM, CODE, READONLY
		ENTRY
		MOV R1, #2
		MOV R2, #3
		MOV R3, #10
		MOV R5, #0
		LDR R0, =data
again	BL pq
		MOV R5, R1
		MOV R1, R2
		CMP R1, #3
		BEQ again
		CMP R5, R2
		BLT print 
		MOV R6, #0
		STR R6, [R0]
fim		B fim
print	STR R5, [R0]
		B fim
pq		STMFD sp!, {R1, R3, lr}			;ARRUMAR: ESTÁ MULTIPLICANDO, NAO ELEVANDO (precisa de um loop a mais para elevar)
		MOV R0, R1						;pode ser que esteja efetuando a potencia uma vez a mais
op		MUL R1, R0, R1
		SUBS R3, #1
		BNE op
		ADD R5, R1
		LDMFD sp!, {R1, R3, pc}
		AREA MYDATA, DATA, READWRITE
data
		END
			
