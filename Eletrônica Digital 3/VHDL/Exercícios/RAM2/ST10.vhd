--Thalita Maria do Nascimento - Equipe 7
--Projeto uProcessador7 RAM
--Entrega 19/11/2018

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ST10 is
	port ( CLK,RST					    			  			  : in std_logic;
			 C,Z				 									  : out std_logic;
			 estado					    						  : out unsigned (1 downto 0);
			 PC						    			  			  : out unsigned (7 downto 0);
			 RD1,RD2,ALUResult,Mem    			  			  : out unsigned (15 downto 0);
			 Instr					    	 		  			  : out unsigned (31 downto 0);
			 WD_s,WD3_s,A_s: out unsigned (15 downto 0);
			 A2_s,A1_s,WriteReg_s: out unsigned (3 downto 0)
		  );
end entity;
 
architecture a_ST10 of ST10 is
	component ula
		port ( ALUSrcA	         				  			  : in std_logic;
				 C,Z								     			  : out std_logic;
				 ALUSrcB								  			  : in unsigned (1 downto 0);
				 ALUOp 						  			  		  : in unsigned (7 downto 0);
				 RD1,RD2,SignImm,Mem		        			  : in unsigned (15 downto 0);
				 ALUResult							  			  : out unsigned (15 downto 0)								  
			  );
	end component;
	
	component banco_regs
		port ( CLK,RST,WE3						  	    	  : in std_logic;
				 A1,A2,A3                       			  : in unsigned (3 downto 0);
				 WD3                            			  : in unsigned (15 downto 0);
				 RD1,RD2                        			  : out unsigned (15 downto 0)
		     );
	end component;
		
	component pcounter
		port ( CLK,RST,WE					 		  			  : in std_logic;
				 PCSrc						 		  		  	  : in unsigned (1 downto 0);
				 JumpAbs,JumpRel			 		  		     : in unsigned (7 downto 0);
				 PC_out						 		  			  : out unsigned (7 downto 0)
			  );
	end component;
		
	component rom
		port ( CLK,RE								  			  : in std_logic;
			    A     								  			  : in unsigned (7 downto 0);
				 RD									  			  : out unsigned (31 downto 0)
			  );
	end component; 
	
	component maq_estados 
		port( CLK,RST,CIn,ZIn		 		    			  : in std_logic;
				RE,WE,RegMemWrite,ALUSrcA  			  	  : out std_logic;
				estado,PCSrc,ALUSrcB		  	    			  : out unsigned (1 downto 0);
				A2										 			  : out unsigned (3 downto 0);
				ALUResult,RD,RD1,RD2							  : in unsigned (15 downto 0);
				A,WD,WD3								 			  : out unsigned (15 downto 0);
				Instr									 			  : in unsigned (31 downto 0)
			 );
	end component;
	
	component ram
		port ( CLK,WE											  : in std_logic;
				 A,WD												  : in unsigned (15 downto 0);
				 RD											 	  : out unsigned (15 downto 0)
		     );
	end component;
	
	signal ALUSrcA,WE,RE,RegMemWrite,CIn,ZIn			  : std_logic;
	signal PCSrc,ALUSrcB					   			  	  : unsigned (1 downto 0);
	signal A1,A2,WriteReg						 	 	  	  : unsigned (3 downto 0);
	signal Op,ALUOp,JumpRel,JumpAbs,PC_s   			  : unsigned (7 downto 0);
	signal RD1_s,RD2_s,SignImm,ALUResult_s,WD3,WD,RD,A: unsigned (15 downto 0);
	signal Instr_s									      	  : unsigned (31 downto 0);
	
begin

	ula_p			  : ula port map 			 ( RD1=>RD1_s,RD2=>RD2_s,SignImm=>
														SignImm,Mem=>RD,ALUResult=>
														ALUResult_s,ALUOp=>ALUOp,ALUSrcA=>
														ALUSrcA,ALUSrcB=>ALUSrcB,C=>CIn,
														Z=>ZIn);
					 			 
	banco_p 		  : banco_regs port map  ( CLK=>CLK,RST=>RST,WE3=>RegMemWrite,
													   A1=>A1,A2=>A2,A3=>WriteReg,WD3=>
													   WD3,RD1=>RD1_s,RD2=>RD2_s);
	
	pc_p			  : pcounter port map 	 ( CLK=>CLK,RST=>RST,WE=>WE,PCSrc=>
														PCSrc,PC_out=>PC_s,JumpAbs=>JumpAbs,
														JumpRel=>JumpRel);
	
	rom_p			  : rom port map 			 ( CLK=>CLK,RE=>RE,A=>PC_s,RD=>Instr_s);														  
																  
	uni_control_p : maq_estados port map ( CLK=>CLK,RST=>RST,CIn=>CIn,ZIn=>ZIn,
														RE=>RE,WE=>WE,RegMemWrite=>
														RegMemWrite,ALUSrcA=>ALUSrcA,estado=>
														estado,PCSrc=>PCSrc,ALUSrcB=>ALUSrcB,
														A2=>A2,ALUResult=>ALUResult_s,RD=>RD,
														RD1=>RD1_s,RD2=>RD2_s,A=>A,Instr=>
														Instr_s);
																							
	ram_p 		  : ram port map 			 ( CLK=>CLK,WE=>RegMemWrite,A=>A,WD=>WD,
														RD=>RD);

														
	WD_s <= WD;

	WD3_s <= WD3;
	
	A_s	<= A;
	
	A2_s		<= A2;
	
	A1_s		<= A1;
	
	WriteReg_s <= WriteReg;
	
	--sinal de flag carry e zero da ULA a ser visualizado no testbench
	
	C 			  <= CIn;
	
	Z			  <= ZIn;
	
	--sinal de saida da ULA para ser visualizado no testbench
	
	ALUResult  <= ALUResult_S;
	
	--sinal de saida do PC para ser visualizado no testbench
	
	PC 		  <= PC_s;
	
	--sinal de saida de Instr para ser visualizado no testbench
	
	Instr      <= Instr_s;
	
	--seleção de registradores do banco para leituras e escrita, respectivamente
	
	A1         <= Instr_s (23 downto 20);
	
	WriteReg   <= A1;
	
	--sinais da saída do banco de registradores para serem visualizados no testbench
	
	RD1		  <= RD1_s;
	
	RD2		  <= RD2_s;
	
	--valor imediato para ULA
	
	SignImm    <= Instr_s (15 downto 0);
	
	--valor para salto relativo
	
	JumpRel    <= Instr_s (23 downto 16);
	
	--valor para salto absoluto
	
	JumpAbs	  <= Instr_s (23 downto 16);
	
	--operação a ser executada pela ULA e saltos pelo PC
 
	Op         <= Instr_s (31 downto 24);
	
	ALUOp 	  <= Op;
	
	--valor da RAM a ser visualizado pelo testbench
	
	Mem 		  <= RD;
	
end architecture;