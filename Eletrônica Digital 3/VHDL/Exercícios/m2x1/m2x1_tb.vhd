library ieee;
use ieee.std_logic_1164.all;
entity m2x1_tb is
end entity;
architecture a_m2x1_tb of m2x1_tb is
	component m2x1
		port( en: in std_logic;
				entr0,entr1: in std_logic;
				sel: in std_logic;
				y: out std_logic
		);
	end component;
	signal en, entr0, entr1, sel, y: std_logic;
	begin
		uut: m2x1 port map(en=>en,entr0=>entr0,entr1=>entr1,sel=>sel,y=>y);
		process
		begin
			en <= '0';
			sel <= '0';
			entr0 <= '0';
			wait for 50 ns;
			en <= '0';
			sel <= '0';
			entr0 <= '1';
			wait for 50 ns;
			en <= '0';
			sel <= '1';
			entr1 <= '0';
			wait for 50 ns;
			en <= '0';
			sel <= '1';
			entr1 <= '1';
			wait for 50 ns;
			en <= '1';
			sel <= '0';
			entr0 <= '0';
			wait for 50 ns;
			en <= '1';
			sel <= '0';
			entr0 <= '1';
			wait for 50 ns;
			en <= '1';
			sel <= '1';
			entr1 <= '0';
			wait for 50 ns;
			en <= '1';
			sel <= '1';
			entr1 <= '1';
			wait for 50 ns;
		end process;
end architecture;

