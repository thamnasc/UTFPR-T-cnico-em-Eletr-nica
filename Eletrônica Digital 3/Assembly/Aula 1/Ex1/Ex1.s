		AREA ARMex, CODE, READONLY   ; ARMex: nome READONLY: apenas leitura
		ENTRY					
	
		MOV R0, #0x11
		MOV R1, #2560
		MVN R2, #4 ; Porta NOT
		MOV R3, #0xDE
		ORR R3, R3, #0X0000C000 ; porta OR
		ORR R3, R3, #0x00ED0000
		ORR R3, R3, #0xFE000000
halt		MOV R4, R1
		;; exemplo de mov
      B halt ; endereço antes do tab com nome halt
		END ; fecha o ENTRY