--Equipe 7 - Thalita Maria do Nascimento
--Unidade de Controle Rudimentar
-- Entrega 01/10/2018 (Entregue dia 03/10/2018)

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity uni_control is
	port ( clk,rst						  : in std_logic; 										 --clk e rst globais
			 registro,mux_data_in	  : out unsigned (6 downto 0); 						 --saida do pc, entrada do pc
			 estado						  : out std_logic; 										 --estado da unidade de controle
			 instr_s						  : out unsigned (11 downto 0) 
		  );
end entity;

architecture a_uni_control of uni_control is 												  --utilizacao de componentes pc, rom e unidade de controle
	component pc
		port ( clk,rst,wr_en			  : in std_logic;
				 data_out,mux_data_in_s: out unsigned (6 downto 0);
				 instr					  : in unsigned (11 downto 0)
		     );
	end component;
	
	component rom
		port ( clk,rst,read_en		  : in std_logic;
				 endereco			     : in unsigned (6 downto 0);
				 dado						  : out unsigned (11 downto 0)
			  );
	end component;
	
	component control
		port ( clk,rst				     : in std_logic;
				 status				     : out std_logic;
				 wr_en,read_en			  : out std_logic
			  );
	end component;
	
signal wr_en,read_en				     : std_logic; 										    			 --enables controlados pela unidade de controle
signal data_out						  : unsigned (6 downto 0); 							 			 --saida do pc para ligar na rom
signal instr							  : unsigned (11 downto 0); 						    			 --conectar saida rom e mux_data_in do pc

begin

pc_uni: pc port map (clk=>clk,rst=>rst,wr_en=>wr_en,data_out=>data_out,
							mux_data_in_s=>mux_data_in,instr=>instr); 
							
rom_uni: rom port map (clk=>clk,rst=>rst,read_en=>read_en,endereco=>data_out,dado=>instr); --endereco da rom controlado pela saida do pc

control_uni: control port map (clk=>clk,rst=>rst,status=>estado,wr_en=>wr_en,read_en=>read_en);
	
instr_s 	<= instr; 												 									          --sinal para verificar saida da rom

registro <= data_out; 															 					          --sinal para verificar saida do pc

end architecture;