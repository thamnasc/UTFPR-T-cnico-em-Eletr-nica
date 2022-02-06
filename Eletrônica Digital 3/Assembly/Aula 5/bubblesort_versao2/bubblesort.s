			AREA ARM, CODE, READONLY	
			ENTRY
 			LDR R3, =data1
			LDR R4, =fim0
			LDR R6, =data2
			SUB R4, #4
			MOV R9, #1
transfer	LDR R8, [R3]
			STR R8, [R6]
			CMP R3, R4
			BEQ start
			ADD R3, #4
			ADD R6, #4
			ADD R9, #1
			B transfer
start		LDR R7, [R6]
			SUB R10,R9,#1
			MOV R8, #1
			MOV R5, #2
again_varr	CMP R8, R5			;continua =!0
			BEQ fim
			LDR R6, =data2		;;i=0
			MOV R8, #0		 	 ;continua=0
			LDR R1, [R6]		 
			LDR R2, [R6, #4]
vrf_maior	CMP R9, R10			;i<fim-1
			BEQ menos_varr		;se igual vai pra fim--
			CMP R1, R2			;X[i]>X[i+1]
			BGT nova_pos		;se R1 for menor vai pra i++
			STR R1, [R6, #4]	;troca
			STR R2, [R6]		;troca
			LDR R1, [R6]
			LDR R2, [R6, #4]
nova_pos	ADD R6, #4			;i++
			MOV R8, #1			;nova posicao
			LDR R1, [R6]
			LDR R2, [R6, #4]
			B vrf_maior
menos_varr	SUB R5, #1			;fim--
			MOV R7, R2
			B again_varr	
fim			B fim
data1
			DCD 5,1,6,4,3
fim0
			AREA MYDATA, DATA, READWRITE
data2		
			END