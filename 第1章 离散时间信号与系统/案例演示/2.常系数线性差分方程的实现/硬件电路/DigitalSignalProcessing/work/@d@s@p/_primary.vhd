library verilog;
use verilog.vl_types.all;
entity DSP is
    port(
        reset           : in     vl_logic;
        clk             : in     vl_logic;
        x               : in     vl_logic_vector(7 downto 0);
        y               : out    vl_logic_vector(7 downto 0)
    );
end DSP;
