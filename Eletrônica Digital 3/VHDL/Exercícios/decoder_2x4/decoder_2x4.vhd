library ieee;
use ieee.std_logic_1164.all;
entity decoder_2x4 is
	port( B: in std_logic;
			A: in std_logic;
			Sa: out std_logic;
			Sb: out std_logic;
			Sc: out std_logic;
			Sd: out std_logic
	);
end entity;
architecture a_decoder_2x4 of decoder_2x4 is
begin
	Sa <= not B and not A;
	Sb <= not B and A;
	Sc <= B and not A;
	Sd <= B and A;
end architecture;