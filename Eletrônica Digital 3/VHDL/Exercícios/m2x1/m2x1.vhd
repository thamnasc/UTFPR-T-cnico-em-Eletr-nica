library ieee;
use ieee.std_logic_1164.all;
entity m2x1 is
	port( en: in std_logic;
			entr0,entr1: in std_logic;
			sel: in std_logic;
			y: out std_logic
	);
end entity;
architecture a_m2x1 of m2x1 is
signal x: std_logic;
begin
	x <= entr0 when sel='0' else
		  entr1 when sel='1' else
		  '0';
	y <= x when en='1' else
	'0';
end architecture;

	