--Thalita Maria do Nascimento - Equipe 7
--Projeto uProcessador6 Salto Condicional
--Entrega 05/11/2018 (Entregue 07/11)

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity calc is
	port ( CLK,RST					    : in std_logic;
			 Instr					    : out unsigned (31 downto 0);
			 RD1,RD2,ALUResult	    : out unsigned (15 downto 0);
			 PC						    : out unsigned (7 downto 0);
			 estado					    : out unsigned (1 downto 0);
			 C,Z							 : out std_logic
			 
	);
end entity;

architecture calc_a of calc is

	component ula_banco
		port ( ALUSrc,CLK,RST,WE3   : in std_logic;
				 C,Z						 : out std_logic;
				 Flag						 : out unsigned (2 downto 0);
				 A1,A2,A3				 : in unsigned (3 downto 0);
				 ALUControl				 : in unsigned (7 downto 0);
				 SignImm					 : in unsigned (15 downto 0);
				 RD1,RD2,ALUResult	 : out unsigned (15 downto 0)
		);
		end component;
		
	component pc_rom
		port ( CLK,RST,WE,RE			 : in std_logic;
				 Instr				    : out unsigned (31 downto 0);
				 PC_out				    : out unsigned (7 downto 0);
				 PCSrc					 : in unsigned (1 downto 0)
		); 
	end component;
	
	component maq_estados 
		port( CLK,RST					 : in std_logic;
				estado					 : out unsigned (1 downto 0);
				FlagIn					 : in unsigned (2 downto 0);
				PCSrc						: out unsigned (1 downto 0);
				Op							 : in unsigned (7 downto 0);
				RE,WE,RegWrite,ALUSrc : out std_logic
		);
	end component;
	
	signal Instr_s						 : unsigned (31 downto 0);
	signal SignImm						 : unsigned (15 downto 0);
	signal Op,ALUControl,JumpRel	 : unsigned (7 downto 0);
	signal A1,A2,WriteReg			 : unsigned (3 downto 0);
	signal FlagIn						 : unsigned (2 downto 0);
	signal PCSrc					    : unsigned (1 downto 0);
	signal ALUSrc,WE,RE,RegWrite	 : std_logic;
	
begin
	
	ula_banco_c							: ula_banco port map ( ALUSrc=>ALUSrc,CLK=>CLK,RST=>RST,
																		  WE3=>RegWrite,ALUControl=>ALUControl,
																		  A1=>A1,A2=>A2,A3=>WriteReg,Flag=>
																		  FlagIn,SignImm=>SignImm,RD1=>RD1,
																		  RD2=>RD2,ALUResult=>ALUResult,C=>C,
																		  Z=>Z);
																		  
	pc_rom_c								: pc_rom port map ( CLK=>CLK,RST=>RST,WE=>WE,RE=>RE,Instr=>
																	  Instr_s,PC_out=>PC,PCSrc=>PCSrc);
																	  
	maq_estados_c						: maq_estados port map ( CLK=>CLK,RST=>RST,estado=>estado, 
																			 FlagIn=>FlagIn,PCSrc=>PCSrc,Op=>Op,
																			 RE=>RE,WE=>WE,RegWrite=>RegWrite,
																			 ALUSrc=>ALUSrc);
																			 
	--sinal de saida de Instr para ser visualizada no testbench
	
	Instr      <= Instr_s;
	
	--seleção de registradores do banco para leituras e escrita, respectivamente
	
	A1         <= Instr_s (23 downto 20);
	
	A2         <= Instr_s (19 downto 16);
	
	WriteReg   <= A1;
	
	--valor imediato para ULA
	
	SignImm    	  <= Instr_s (15 downto 0);
	
	--valor a ser estendido para salto relativo (posição da rom desejada)
	
	JumpRel   	  <= Instr_s (23 downto 16);
	
	--operação a ser executada pela ULA
 
	Op         <= Instr_s (31 downto 24);
	
	ALUControl <= Op;
	
end architecture;
	
	