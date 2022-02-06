--Thalita Maria do Nascimento - Equipe 7
--Projeto uProcessador7 RAM - Crivo de Eratóstenes
--Entrega 26/11/2018

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ST10 is
	port ( C,Z				 	   		  : out std_logic;
			 estado							  : out unsigned (1 downto 0);
			 Primo							  : out unsigned (3 downto 0);
			 PC								  : out unsigned (7 downto 0);
			 RD1,RD2,RD,ALUResult		  : out unsigned (15 downto 0);
			 Instr							  : out unsigned (31 downto 0)
		  
			 -- sinais que sao usados no toplevel (substituem o que vinha do testbench)
			 RST   							  : in std_logic;  -- KEY0 R22
			 CLK_H 							  : in std_logic;  -- L1 (50 MHz)
		
			 -- sinais que são a interface de teste no HW físico
			 HALT_KEY 						  : in std_logic; 	-- SW9: L2
			 TURBO_EN 						  : in std_logic; 	-- SW8: M1
			 LED								  : out unsigned (9 downto 4);  -- LED9..LED6
			 HEX0 							  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			 HEX1 							  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0); -- (max 99)
			 HEX2 							  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0); -- sempre apagados
			 HEX3 							  : OUT STD_LOGIC_VECTOR(6 DOWNTO 0)  -- sempre apagados
		  );
end entity;
 
architecture a_ST10 of ST10 is
	component ula
		port ( ALUSrcA	         		  : in std_logic;
				 C,Z				   		  : out std_logic;
				 ALUSrcB						  : in unsigned (1 downto 0);
				 ALUOp 						  : in unsigned (7 downto 0);
				 SrcA,SrcB		   		  : in unsigned (15 downto 0);
				 ALUResult					  : out unsigned (15 downto 0)								  
			  );
	end component;
	
	component banco_regs
		port ( CLK,RST,WE3				  : in std_logic;
				 A1,A2,A3         		  : in unsigned (3 downto 0);
				 Primo						  : out unsigned (3 downto 0);
				 WD3              		  : in unsigned (15 downto 0);
				 RD1,RD2          		  : out unsigned (15 downto 0)
		     );
	end component;
		
	component pcounter
		port ( CLK,RST,WE		   		  : in std_logic;
				 PC_out						  : out unsigned (7 downto 0);
				 PC1				   		  : in unsigned (7 downto 0) 
			  );
	end component;
		
	component rom
		port ( CLK,RE						  : in std_logic;
			    A     						  : in unsigned (7 downto 0);
				 RD							  : out unsigned (31 downto 0)
			  );
	end component; 
	
	component uni_control 
		port ( CLK,RST					     : in std_logic;
				 RE,WE,RegMemWrite,ALUSrcA: out std_logic;
				 estado,ALUSrcB		 	  : out unsigned (1 downto 0);
				 Op							  : in unsigned (7 downto 0);
				 ALUOp,Jump					  : out unsigned (7 downto 0)
			  );
	end component;
	
	component ram
		port ( CLK,WE						  : in std_logic;
				 A,WD							  : in unsigned (15 downto 0);
				 RD							  : out unsigned (15 downto 0)
		     );
	end component;
	
	component RAMDisp is
		port ( clk 							  : in std_logic;
				 endereco 					  : in unsigned (15 downto 0);
				 wr_en 						  : in std_logic;
				 dado_in 					  : in unsigned (15 downto 0);
				 dado_out 					  : out unsigned (15 downto 0);
				
				 --- sinais adicionais da RAMDisp
				 -- decodificação 7seg
				 HEX0 						  : OUT STD_LOGIC_VECTOR (6 DOWNTO 0);
				 HEX1 						  : OUT STD_LOGIC_VECTOR (6 DOWNTO 0); --(max 99)
				 HEX2 						  : OUT STD_LOGIC_VECTOR (6 DOWNTO 0);
				 HEX3 						  : OUT STD_LOGIC_VECTOR (6 DOWNTO 0);
				 -- divisão de clock 
				 rst    						  : in std_logic;
				 clk_h  						  : in std_logic;
				 turbo  						  : in std_logic;
				 halt   						  : in std_logic;
				 clk_div						  : out std_logic
			  );
	end component RAMDisp;

	-- Sinais do MikroP declarados apenas para não deixar sinais de entrada da RAM flutuando
	SIGNAL enderecoRAMDisp: unsigned(15 downto 0);
	SIGNAL wr_enRAMDisp: std_logic;
	SIGNAL dado_inRAMDisp: unsigned(15 downto 0):="0000000000000000";
	
	
	Signal Primo_out,Primo_in: unsigned (4 downto 0);
	signal clk_div: std_logic;  -- esse é o clock divido de maneira variável pelas teclas TURBO e HALT
	
	signal WE,RE,RegMemWrite			  													: std_logic;
	signal ALUSrcA,CIn,ZIn,Zout,Cout,CorZ,EQ,NE,ULT,ULE,UGE,UGT					: std_logic;
	signal ALUSrcB					   			  	  										: unsigned (1 downto 0);
	signal PCSrc																				: unsigned (1 downto 0);
	signal R03,WBR																				: unsigned (1 downto 0);
	signal estado_s																			: unsigned (1 downto 0);
	signal A1,A2,A2_s,WriteReg						 	 	  	  							: unsigned (3 downto 0);
	signal Jump,JumpRel,JumpAbs,PC_s,PCPlus1,PCJump,PC1,JumpRelNot,JumpRelC2: unsigned (7 downto 0);
	signal Op,ALUOp											  								: unsigned (7 downto 0);
	signal RD1_s,RD2_s,RD2Plus1,WD3														: unsigned (15 downto 0);
	signal SrcA,SrcB,SignImm,ALUResult_s												: unsigned (15 downto 0);
	signal WD,RD_s,A																			: unsigned (15 downto 0);
	signal Instr_s									      	  								: unsigned (31 downto 0);
	
begin

	ula_p			  : ula port map 			 ( ALUSrcA=>ALUSrcA,C=>CIn,Z=>ZIn,
													   ALUSrcB=>ALUSrcB,ALUOp=>ALUOp,SrcA=>
														SrcA,SrcB=>SrcB,ALUResult=>
														ALUResult_s);
					 			 
	banco_p 		  : banco_regs port map  ( CLK=>CLK,RST=>RST,WE3=>RegMemWrite,
													   A1=>A1,A2=>A2,A3=>WriteReg,Primo=>
														Primo_in,WD3=>WD3,RD1=>RD1_s,RD2=>
														RD2_s);
	
	pc_p			  : pcounter port map 	 ( CLK=>CLK,RST=>RST,WE=>WE,PC_out=>
														PC_s,PC1=>PC1);
	
	rom_p			  : rom port map 			 ( CLK=>CLK,RE=>RE,A=>PC_s,RD=>Instr_s);														  
																  
	uni_control_p : uni_control port map ( CLK=>CLK,RST=>RST,RE=>RE,WE=>WE,
														RegMemWrite=>RegMemWrite,ALUSrcA=>
														ALUSrcA,estado=>estado_s,ALUSrcB=>
														ALUSrcB,Op=>Op,Jump=>Jump,ALUOp=>
														ALUOp);
																							
	ram_p 		  : ram port map 			 ( CLK=>CLK,WE=>RegMemWrite,A=>A,WD=>WD,
														RD=>RD_s);
														
	RAMeDISP		  : RAMDisp
	PORT MAP (	
					clk=>clk_h,
					endereco => enderecoRAMDisp,
					dado_in=> dado_inRAMDisp,
					--dado_out => ram_out, -- sinal ligado ao processador
					wr_en=> wr_enRAMDisp,
					
					rst    => RST,
					clk_h  => CLK_H,  
					turbo => TURBO_EN,
					halt => HALT_KEY,
					clk_div => clk_div,
					
					HEX0=>HEX0, 
					HEX1=>HEX1, 
					HEX2=>HEX2, 
					HEX3=>HEX3
				);
				
	-- Processo Exemplo que roda na cadência de clk_div
	process (clk_div, RST)
   Begin
		If RST = '0' then
			Primo_out <= "00000";
		elsif clk_div' event and clk_div = '1' then
			Primo_out <= Primo_in;
		end if;
	end process;

	
	
-- 	Parte combincional assíncrona

	enderecoRAMDisp <= "0000000001111111"; -- endereço 127
	wr_enRAMDisp <= '1';
	dado_inRAMDisp (4 downto 0) <= Primo_out;
	
	LED(9) <= Primo_out(4);   -- LED9  pino R17 
	LED(8) <= Primo_out(3);   -- LED8  pino R18
	LED(7) <= Primo_out(2);	-- LED7  pino U18
	LED(6) <= Primo_out(1);	-- LED6  pino Y18
	LED(5) <= Primo_out(0);  --LED pino V19

	--visualização do estado no testbench
	
	estado 	  <= estado_s;
	
	--seleção de SrcA da ULA
	
	SrcA		  <= RD_s when ALUSrcA='1' else
					  RD1_s;
	
	--seleção de SrcB da ULA
	
	SrcB       <= SignImm when ALUSrcB="01" else
					  RD_s when ALUSrcB="10" else
					  RD2_s;
	
	--registro do flag da ULA
	
	process(CLK,RST,estado_s)
	begin
		if RST='1' then
			Zout 				<= '0';
		elsif rising_edge (CLK) then
			if estado_s="10" then
				Zout  		<= ZIn;
			end if;
		end if;
	end process;
	
	process(CLK,RST,estado_s)
	begin
		if RST='1' then
			Cout 				<= '0';
		elsif rising_edge (CLK) then
			if estado_s="10" then
				Cout  		<= CIn;
			end if;
		end if;
	end process;
	
	--signal do primo a ser visualizado no testbench
	
	Primo 	  <= Primo_in;
	
	--sinal de flag carry e zero da ULA a serem visualizados no testbench
	
	C 			  <= Cout;
	
	Z			  <= Zout;
	
	--sinal de saida da ULA para ser visualizado no testbench
	
	ALUResult  <= ALUResult_S;
	
	--sinal de saida do PC para ser visualizado no testbench
	
	PC 		  <= PC_s;
	
	--sinal de saida de Instr para ser visualizado no testbench
	
	Instr      <= Instr_s;
	
	--seleção de registradores do banco para leitura (RD1) e escrita (A3), respectivamente
	
	A1         <= Instr_s (23 downto 20);
	
	WriteReg   <= A1;
	
	--Registradores para endereço indireto
	
		--Para algumas operações da ULA, apenas os 4 primeiros registradores são usados, 
		--podendo ter offset ou não no endereçamento da RAM. O Opcode para essas duas opções
		--é o mesmo, o que diferencia é o "11XX" e "10XX" antes dos bits 17 e 16 que formam
		--combinações de 0 a 3 para selecionar os registradores de RD2.
	
	R03		  <= Instr_s (19 downto 18);
	
	A2_s		  <= '0' & '0' & Instr_s (17 downto 16);
	
	A2         <= A2_s when Op=X"08" or Op=X"68" or Op=X"48" or Op=X"28" else
					  Instr_s (19 downto 16);
	
	--Endereçamento da RAM
	
		--conta para obter offset 
	RD2Plus1	  <= RD2_s+1;
	
	A			  <= RD2_s when Op=X"08" and R03="10" else
					  RD2Plus1 when Op=X"08" and R03="11" else
					  RD2_s when Op=X"28" and R03="10" else
					  RD2Plus1 when Op=X"28" and R03="11" else
					  RD2_s when Op=X"68" and R03="10" else
				     RD2Plus1 when Op=X"68" and R03="11" else
					  RD2_s when Op=X"48" and R03="10" else
					  RD2Plus1 when Op=X"48" and R03="11" else
					  RD2_s when Op=X"A8" else
					  RD2Plus1 when Op=X"98" else
					  RD1_s when Op=X"B8" else
					  Instr_s (15 downto 0);
								
	--enable para escrever na RAM ou no banco
		
		--por conta de ter características RISC e CISC, o processador pode realizar
		--operações diretamente na memória RAM. Assim, escrever no banco ou na RAM
		--é uma etapa ativada pelo mesmo estado da unidade de controle. Para controlar
		--o destino do dado, foi feito um enable para as seleçoes de entrada de cada componente.
	
	WBR		  <= "01" when Op=X"04" or Op=X"64" or Op=X"F6" or Op=X"24" else
					  "01" when Op=X"B8" else
					  "10" when Op=X"FA" or Op=X"2D" or Op=X"3D" or Op=X"8D" or Op=X"9D" or Op=X"ED" or Op=X"FD" else
					  "00";
								
	--DEMUX para selecionar armazenamento (Banco ou RAM respectivamente)
	
		--banco
		
	WD3 		  <= ALUResult_s when WBR="00" else
					  RD1_s;
			 
		--RAM
		
	WD	 		  <= ALUResult_s when WBR="01" else
					  RD_s;
	
	--sinais da saída do banco de registradores para serem visualizados no testbench
	
	RD1		  <= RD1_s;
	
	RD2		  <= RD2_s;
	
	--valor da RAM a ser visualizado pelo testbench
	
	RD 		  <= RD_s;
	
	--valor imediato para ULA
	
	SignImm    <= Instr_s (15 downto 0);
	
	--valor para salto relativo
	
	JumpRel    <= Instr_s (23 downto 16);
	
	--valor para salto absoluto
	
	JumpAbs	  <= Instr_s (23 downto 16);
	
	--operação a ser executada pela ULA e saltos pelo PC
 
	Op         <= Instr_s (31 downto 24);
	
	--PC1 sem jump
	
	PCPlus1	  <= PC_s+1;
	
	--enable do Jump
								
		--"01" corresponde a jump relativo, "10" a absoluto e "00" a soma normal do PC
		
	PCSrc		  <= "01" when Jump=X"2D" and EQ='1' else
					  "01" when Jump=X"3D" and NE='0' else
				     "01" when Jump=X"8D" and ULT='1' else
					  "01" when Jump=X"FD" and ULE='1' else
					  "01" when Jump=X"9D" and UGE='0' else
					  "01" when Jump=X"ED" and UGT='0' else
					  "10" when Jump=X"FA" else
					  "00";		
					  
		--flags de condição para salto relativo
			--EQ - Equal
			--NE - Not Equal
			--ULT - Unsigned less than
			--ULE - Unsigned less than or equal
			--UGE - Unsigned bigger than or equal
			--UGT - Unsigned bigger than
		
	CorZ		  <= Cout or Zout;					
							
	EQ 		  <= Zout;
	
	NE			  <= Zout;
	
	ULT		  <= Cout;
	
	ULE		  <= CorZ;
	
	UGE		  <= Cout;
	
	UGT		  <= CorZ;
	
	--complemento de 2 da posição a ser saltada da rom
	
	JumpRelNot <= not JumpRel;
	
	JumpRelC2  <= JumpRelNot+1;
								
	--salto relativo é a soma do complemento de 2 da posição desejada com a posição atual da rom
	
	PCJump	  <= PC_s+JumpRelC2;
	
	--PCPlus1 quando PCSrc desativado
	--salto condicional (relativo) e desvio (absoluto,incondicional) quando 01 e 10, respectivamente
	
	PC1   	  <= PCPlus1 when PCSrc="00" else
					  PCJump when PCSrc="01" else
					  JumpAbs when PCSrc="10" else 
					  X"00";
	
end architecture;