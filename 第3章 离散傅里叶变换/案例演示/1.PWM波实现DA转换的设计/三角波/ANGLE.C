#include<math.h>
#include<stdio.h>
#define Pi 3.1415926

float xa(float t)
{
   if(t<0.01)
      return( 100*t );
   else
      return ( 1 - 100*(t-0.01));
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