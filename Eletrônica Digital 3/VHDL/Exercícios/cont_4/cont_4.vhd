library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity cont_4 is
	port ( rst,clk,en,clr,ld: in std_logic;
			 load: in unsigned (3 downto 0);
			 Q: out unsigned (3 downto 0)
		  );
end entity;

architecture a_cont_4 of cont_4 is
signal cont: unsigned (3 downto 0);
begin
	process (clk,rst)
		begin
			if rst='1' then
				cont <= "0000";
			elsif clk' event and clk='1' then
				if clr='1' then
					cont <= "0000";
				else
					if en='1' then
						if ld='1' then
							cont <= load;
						else
							cont <= cont+1;
						end if;
					end if;
				end if;
			end if;
	end process;
	Q <= cont;
end architecture;

					
			 