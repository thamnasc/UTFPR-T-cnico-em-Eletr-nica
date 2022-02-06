			AREA ARM, CODE, READONLY
			ENTRY
            MOV R0,#0
            MOV R1,#0
volta   	ADD R0,R1
            ADD R1,#1
            CMP R1,#10
            BLE volta
fim         B  fim
            END
