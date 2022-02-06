library ieee;
use ieee.std_logic_1164.all;
entity adder1bit_tb is
end entity;
architecture a_adder1bit_tb of adder1bit_tb is
		component adder1bit
			port( B, A: in std_logic;
				   Cout, Adder: out std_logic
				 );
		end component;
		signal B, A, Cout, Adder, BnA, BAn: std_logic;
		begin
			uut: adder1bit port map(B=>B, A=>A, Cout=>Cout, Adder=>Adder, BnA=>BnA, BAn=>BAn);
			process
				begin
					B <= '0';
					A <= '0';
					wait for 50 ns;
					B <= '0';
					A <= '1';
					wait for 50 ns;
					B <= '1';
					A <= '0';
					wait for 50 ns;
					B <= '1';
					A <= '1';
					wait for 50 ns;
			end process;
end architecture;
					
