			AREA ARM, CODE, READONLY
			LDR R0, =data1
			LDR R8, [R0]
			MOV R1, #0xF
			MOV R3, #1
			MOV R5, #0
			MOV R7, #0
			MOV R9, #0
			BL hexa
			LDR R0, =data
			STR R5, [R0]
fim			B fim
hexa		STMFD sp!, {R8, lr}
again		AND R2, R1, R8			;pega o nibble
			LSR R2, R9
			ADD R9, #4
			MUL R6, R3, R2
			MUL R3, R1, R3			;valor a ser multiplicado (multiplo de 16)
			CMP R6, 
			ADD R5, R6
			ADD R7, #1
			CMP R7, #8
			BEQ load
			LSL R1, #4			;shifta o valor de controle pra pegar  nibble
			B again
load
			LDMFD sp!, {R0, pc}
			
data1		dcd 0x7B
fim1
			AREA MYDATA, DATA, READWRITE
data	
			END