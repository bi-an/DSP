`timescale 1ns / 1ps
module testbench;
   
    reg reset;
    reg clk;
    reg [7:0] x;
    wire [7:0] y;

    DSP dsp_inst (
                  .reset(reset),
                  .clk(clk),
                  .x(x),
                  .y(y)
                );

    always  #5 clk = ~clk;

initial
    begin
             #0 reset = 0;
                clk = 0;
                x = 0;
            #5 reset = 1;
            #5 reset = 0;
            #5  x = 1;
            #20 x = 2;
            #20 x = 3;
            #20 x = 4;
            #20 x = 5;
            #20 x = 6;
            #20 x = 7;
            #20 x = 8;
            #20 x = 9;
            #20 x = 0;
            #100 $stop;
    end

endmodule