library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity maq_estados is
	port( clk,rst: in std_logic;
			estado: out unsigned (1 downto 0);
			read_en,wr_en,ALUControl: out unsigned (1 downto 0)
	);
end entity;

architecture a_maq_estados of maq_estados is
	signal estado_s: unsigned (1 downto 0);
begin 
	process(clk,rst)
	begin
		if rst='1' then
			estado_s <= "00";
		elsif rising_edge (clk) then
			if estado_s="10" then
				estado_s <= "00";
			else
				estado_s <= estado_s+1
			end if;
		end if;
	end process;
	estado <= estado_s;
	
	read_en <= '1' when estado_s="00" else
				  '0';
	wr_en	  <= '1' when estado_s="01" else
				  '0';
	ALUControl <= '1' when estado_s="10" else
					  '0';

end architecture;