module DSP(reset,clk ,x,y);
       input reset;
       input clk;
       input [7:0] x;
       output [7:0] y;
       reg[7:0] y_1;
       reg[7:0] y;
       
                       
       always @(posedge clk or posedge reset)
         if(reset)
                   y_1 <= 0;
         else
                   y_1 <= y;
    
        always @(posedge clk or posedge reset)
        if(reset)
                  y <= 0;
        else
                  y <= x + y_1;
         

endmodule
