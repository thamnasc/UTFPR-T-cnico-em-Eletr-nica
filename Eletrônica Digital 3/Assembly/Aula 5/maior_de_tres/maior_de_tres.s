			AREA ARM, CODE, READONLY	
			ENTRY
 			LDR R0, =num0
			LDR R1, =num1
			LDR R2, =data2
			LDR R13, =fim0
			MOV R11, #0
			MOV R12, #2
inicio		SUB R1, #4
			MOV R4, #0
transfer	LDR R5, [R0]	 	;fim=tamanho mem
			STR R5, [R2]
			CMP R0, R1
			BEQ start
			ADD R0, #4
			ADD R2, #4
			ADD R4, #1
			B transfer	   
start		ADD R11, #1
			MOV R5, #1			;continua=1
again_varr	CMP R5, R4			;continua =!0
			BEQ num
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
num			ADD R1, #4
			CMP R1, R0
			BEQ maior
			CMP R11, R12
			BLT chance1
			BEQ chance2
chance1		LDR R9, [R0, #4]
			LDR R0, =num1
			LDR R1, =num2
			LDR R2, =data2
			B inicio
chance2		LDR R10, [R0, #4]
			LDR R0, =num2
			LDR R1, =fim0
			LDR R2, =data2
			B inicio
maior		LDR R13, [R0, #4]														;problema:nao está salvando o 456 (00 00 01 c8)
			CMP R9, R10			;compara num0 com num1
			BGT comp_num02
			CMP R10, R13		;compara num1 com num2
			BGT maior_1
comp_num02	CMP R9, R13
			BGT maior_0
			MOV R0, R13			;num2 é maior
maior_0		MOV R0, R9			;num0 é maior
maior_1		MOV R0, R10			;num1 é maior
fim			B fim
num0		DCD 123,1,2,3															;problema:precisa zerar a memoria antes de colocar novos dados: guardar 4, somar 1 adicionar zeros nessa proporção
num1		DCD 456
			DCD 1,1,1,1,1,1
num2 		DCD -23
fim0
			AREA MYDATA, DATA, READWRITE
data2		
			END