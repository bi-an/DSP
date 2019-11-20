
$MOD51

$TITLE(BLINKING LIGHTS TEST)



Reset:
        MOV DPTR,#SINDATA 
        MOV R0,#00H

MAINLOOP:
        MOV  A,R0
        MOVC A,@A+DPTR 
        MOV  P2,A
        LCALL Delay1ms
                
        INC R0
        CJNE R0,#10,MAINLOOP
        
        MOV  R0,#0
        LJMP MAINLOOP    
  
Delay1ms:
          
          MOV R1,#250
   LOOP1: NOP
          NOP
          DJNZ R1,LOOP1
          RET

SINDATA:  DB 0FFH,0E6H,0A6H,58H,18H,00H,18H,58H,0A6H,0E6H

END
