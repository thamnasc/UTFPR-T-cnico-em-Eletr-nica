library ieee;
use ieee.std_logic_1164.all;
entity adder1bit is
	port( B, A: in std_logic;
			Cout, Adder: out std_logic
		 );
end entity;
architecture a_adder1bit of adder1bit is
signal BnA, BAn: std_logic;
begin
	BnA <= not B and A;
	BAn <= B and not A;
	Adder <= BnA or BAn;
	Cout <= B and A;
end architecture;

			