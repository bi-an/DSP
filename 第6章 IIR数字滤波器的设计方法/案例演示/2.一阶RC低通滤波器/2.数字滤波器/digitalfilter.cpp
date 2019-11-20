#include"graphics.h"
#include<math.h>
#include<conio.h>

#define Pi  3.1415926

/* y(n) = x(n) - 0.5y(n-1) */
float DigitalSystem(float x)
{
   static float y_1=0;
   float R,C,fs,T,a,b,y;
   R = 1000;
   C = 0.000001;
   fs = 100000;
   T = 1/fs;
   a = T/(R*C);
   b = exp(-1.0*a);

   y = a*x  +b*y_1;
   y_1 = y;
   return(y);	
}


void delay()
{
    int i,j;
	for(i=0;i<10000;i++)
	  for(j=0;j<10000;j++)
			;
}

void main()
{
  int driver=VGA,mode=VGAHI;
  float x[150],y[150],fs=20000,T,f;
  int n;
  
   initgraph(&driver,&mode,"");
   
                  
   T  = 1/fs;
   for(f=0;f<=fs/2;f=f+10)
   {
       cleardevice();
	   for(n=0;n<150;n++)
	   {
          x[n] = cos(2*Pi*f*n*T);
          setcolor(WHITE);
	      line(n*4,120,n*4,120-40*x[n]);
      
          y[n] = DigitalSystem(x[n]);
          setcolor(YELLOW);line(10,270,600,270),line(10,430,600,430);
		  line(n*4,350,n*4,350-40*y[n]);
	   }
	   delay();
  }
   getch();
  closegraph();
}