library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder is
	port ( in_a, in_b: unsigned (15 downto 0);
			 carry: out std_logic;
			 sum: unsigned (15 downto 0)
	);
end adder;

architecture a_adder of adder is
signal: c_in, c_out: std_logic;
begin
	sum <= in_a and in_b