library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity cont4_tb is
end entity;

architecture a_cont4_tb of cont4_tb is

	component cont4 is
		port ( rst,clk,en,clr,ld: in std_logic;
				 load: in unsigned (3 downto 0);
				 Q: out unsigned (3 downto 0)
			  );
	end component;
signal rst,clk,en,clr,ld: std_logic;
signal load,Q: unsigned (3 downto 0);

	begin
		DUT:cont4
			port map (clk=>clk,rst=>rst,Q=>Q,
						 en=>en,clr=>clr,ld=>ld,
						 load=>load);
	process
		begin
			clk <= '0';
			wait for 15 ns;
			clk <= '1';
			wait for 15 ns;
		end process;
	end architecture;
	
