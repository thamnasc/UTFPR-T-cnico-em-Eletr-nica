library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity pc is
	port ( clk,rst,wr_en: in std_logic;
			 data_out: out unsigned (6 downto 0)
		  );
end entity;

architecture a_pc of pc is
	
signal registro,data_out_sum,data_in_sum: unsigned (6 downto 0);

begin
	process(clk,rst,wr_en)
		begin
		if rst='1' then
			registro <= "0000000";
		elsif wr_en='1' then
			if rising_edge(clk) then
				registro <= data_in_sum;
			end if;
		end if;
	end process;
	data_in_sum <= data_out_sum;
	data_out <= registro;
	data_out_sum <= registro+1 when registro<"1111111" else
						 "0000000" when registro="1111111" else
						 "0000000";
end architecture;