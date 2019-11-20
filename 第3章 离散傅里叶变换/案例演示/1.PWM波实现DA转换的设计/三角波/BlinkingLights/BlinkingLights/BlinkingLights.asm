
$MOD51

$TITLE(BLINKING LIGHTS TEST)


        ORG 0000H
RESET:  LJMP MAIN

        ORG 000BH
        LJMP T0_ISR

 MAIN:
        MOV TH0,0FFH
        MOV TL0,04H
        MOV TMOD,11H
        MOV 30H,#255
      
       
        MOV R0,30H
        
        MOV  R2,00H
        MOV  DPTR,#SINDATA
        MOV  A,R0
        MOVC A,@A+DPTR
        MOV  R1,A
 
        SETB EA
        SETB ET0
        
        SETB TR0
        SETB P1.0
       
       
MAINLOOP:
         AJMP MAINLOOP

T0_ISR:
        CLR EA
        MOV TH0,#0FFH
        MOV TL0,#04H
        MOV A,R1
        JNZ  NEXT1
        CLR  P1.0
        AJMP NEXT2
NEXT1:  DEC  R1
NEXT2:  MOV A,R0
        JNZ  NEXT3
        SETB P1.0
        INC  R2
        MOV  A,R2
        CJNE A,#20,NEXT5
        MOV  A,#00H
        MOV  R2,#00H
NEXT5:
        MOVC A,@A+DPTR
        MOV  R1,A
        MOV  R0,30H
        AJMP NEXT4   
NEXT3:        
        DEC R0
NEXT4:  
        SETB EA
        RETI
SINDATA:DB 00H,19H,33H,4CH,66H,7FH,99H,0B2H,0CCH,0E5H
        DB 0FEH,0E5H,0CCH,0B2H,98H,7fH,65H,4CH,32H,19H


       END
