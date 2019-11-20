#include"graphics.h"
#include"IIR.h"
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

#define Pi  3.1415926

void delay(float f)
{
    int i,j;

	if(f==0 || f ==800 || f ==1120 || f ==1000 ||f==1500||f==5000) 
		getch();
	else if(f<=1500)
	{
		for(i=0;i<2500;i++)
	      for(j=0;j<10000;j++)
			;
	}
    else
	{
	  for(i=0;i<250;i++)
	      for(j=0;j<10000;j++)
			;
	}
   cleardevice();
}

void show_info(float f)
{
     char str[50];
   	 setcolor(WHITE);
	 line(0,270,639,270),
	 line(0,430,639,430);
	 setcolor(YELLOW);
	 line(0,350-80*0.707,639,350-80*0.707);
	 line(0,350-80*0.1,639,350-80*0.1);
	 setcolor(WHITE);
     sprintf(str,"f = %.2f Hz",f);
	 outtextxy(100,200,str);
	 outtextxy(0,252," 0dB");
	 outtextxy(0,277,"-3dB");
	 outtextxy(0,325,"-20dB");
	 delay(f);
}

void main()
{
  int driver=VGA,mode=VGAHI;
  float x[300],y[300],fs,T,f;
   int n;
  
   initgraph(&driver,&mode,"");
   
   fs = 10000;               
   T  = 1/fs;
   for(f=0;f<=fs/2;f=f+10)
   { 
	   for(n=0;n<300;n++)
	   {
          x[n] = cos(2*Pi*f*n*T);           line(40+n*2,100,40+n*2,100-80*x[n]);
          
		  y[n] = Digital_System(x[n]);      line(40+n*2,350,40+n*2,350-80*y[n]);
	   }
       show_info(f);
  }
  closegraph();
}
