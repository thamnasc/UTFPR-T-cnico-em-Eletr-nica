			AREA ARM, CODE, READONLY	
			ENTRY
 			LDR R0, =data1
			LDR R1, =fim0
			LDR R2, =data2
			LDR R9, =0x00ABACA7E
			SUB R1, #4
			MOV R4, #0
transfer	LDR R5, [R0]	 	;fim=tamanho mem
			ADD R5, R9
			STR R5, [R2]
			CMP R0, R1
			BEQ start
			ADD R0, #4
			ADD R2, #4
			ADD R4, #1
			B transfer
start		MOV R9, R4
			MOV R5, #1			;continua=1
again_varr	CMP R5, R4			;continua =!0
			BEQ result
			LDR R0, =data2		;;i=0
			MOV R6, #0			
			MOV R5, #0		 	 ;continua=0
			LDR R7, [R0]		 
			LDR R8, [R0, #4]
vrf_maior	CMP R6, R4			;i<fim-1
			BEQ menos_varr		;se igual vai pra fim--
			CMP R7, R8			;X[i]>X[i+1]
			BLT nova_pos		;se R1 for menor vai pra i++
			STR R7, [R0, #4]	;troca
			STR R8, [R0]		;troca
			LDR R7, [R0]
			LDR R8, [R0, #4]
nova_pos	CMP R6, R4
			BEQ menos_varr
			ADD R0, #4			;i++
			MOV R5, #1			;nova posicao
			ADD R6, #1
			CMP R6, R4
			BEQ menos_varr
			LDR R7, [R0]
			LDR R8, [R0, #4]
			B vrf_maior
menos_varr	SUB R4, #1	;fim--	
			B again_varr			
result		LDR R2, =data2
			MOV R10, #1
			ADD R9, #1
loop_2nd	SUBS R11, R9, R10
			BEQ second
			ADD R10, #1
			ADD R2, #4
			B loop_2nd
second		LDR R5, [R2, #-4]		;segundo maior
			LDR R2, =data2
			MOV R10, #1
			MOV R6, R9
			LSR R9, #1
med			SUBS R11, R9, R10		
			BEQ scan
			ADD R10, #1
			ADD R2, #4
			B med
scan		TST R6, #1
			BEQ even
			LDR R6, [R2]			;impar
			B fim
even		LDR R6, [R2]		
			LDR R7, [R2, #4]
			ADD R8,R7, R6
			LSR R8, #1				;par
fim		    B fim
data1
			DCD 1,2,3,0x44444,-3999,6,7888,0xdfff,777,88888
fim0
			AREA MYDATA, DATA, READWRITE
data2		
			END