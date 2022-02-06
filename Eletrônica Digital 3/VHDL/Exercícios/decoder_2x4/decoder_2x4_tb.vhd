library ieee;
use ieee.std_logic_1164.all;
entity decoder_2x4_tb is
end entity;
architecture a_decoder_2x4_tb of decoder_2x4_tb is
	component decoder_2x4
		port( B: in std_logic;
				A: in std_logic;
				Sa: out std_logic;
				Sb: out std_logic;
				Sc: out std_logic;
				Sd: out std_logic
		);
	end component;
	signal B, A, Sa, Sb, Sc, Sd: std_logic;
	begin
		uut: decoder_2x4 port map(B=>B, A=>A, Sa=>Sa, Sb=>Sb, Sc=>Sc, Sd=>Sd);
		process
		begin
			B <= '0';
			A <= '0';
			wait for 50ns;
			B <= '0';
			A <= '1';
			wait for 50ns;
			B <= '1';
			A <= '0';
			wait for 50ns;
			B <= '1';
			A <= '1';
			wait for 50ns;
		end process;
end architecture;
