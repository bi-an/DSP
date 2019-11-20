#include<math.h>
#include<stdio.h>
#define Pi 3.1415926

float xa(float t)
{
   return(0.5+0.5*cos(2*Pi*50*t));
}

void main()
{
   int n,y[20];
   float x[20];
   float fs = 1000.0,T;
   clrscr();
   T = 1/fs;
   for(n=0;n<20;n++)
   {
      x[n] = xa(n*T);
      printf("%.3f  ",x[n]);
   }
   getch();
   clrscr();
   printf("\n");
   for(n=0;n<20;n++)
   {
      y[n] = x[n]*255;
      printf("%.3f  %xH    \n",x[n],y[n]);
   }
   getch();
}
