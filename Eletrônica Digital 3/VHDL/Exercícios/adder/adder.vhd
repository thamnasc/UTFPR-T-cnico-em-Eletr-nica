library ieee;
use ieee.std_logic_arith;
use ieee.std_logic_1164.all;
entity adder is
	port(B, A: in std_logic;
		  y: out std_logic
		  );
end entity;
architecture a_adder of adder is
begin
y <= B+A;
end architecture;
