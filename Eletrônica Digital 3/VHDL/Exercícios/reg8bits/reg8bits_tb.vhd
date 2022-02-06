library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity reg8bits_tb is
end entity;

architecture a_reg8bits_tb of reg8bits_tb is
	component reg8bits
		port( clk,rst,wr_en: in std_logic;
				data_in: in unsigned(7 downto 0);
				data_out: out unsigned(7 downto 0)
		);
	end component;
	signal clk,rst,wr_en: std_logic;
	signal data_in,data_out: unsigned;
	
	begin
		uut: reg8bits port map(clk=>clk,rst=>rst,wr_en=>wr_en,data_in=>data_in,data_out=>data_out);
		
		process
		begin
			clk <= '0';
			wait for 50 ns;
			clk <= '1';
			wait for 50 ns;
		end process;
		
		process
		begin
			rst <= '1';
			wait for 100 ns;
			rst <= '0';
			wait;
		end process;
		
		process
		begin
			wait for 100 ns;
			wr_en <= '0';
			data_in <= "11111111";
			wait for 100 ns;
			data_in <= "10001101";
		end process;
end architecture;
