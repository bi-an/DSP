#include<math.h>
#include<stdio.h>
#define Pi 3.1415926
#define N  10

float xa(float t)
{
   return( 0.5+0.5*cos(2*Pi*100*t) );
}

void main()
{
       float x[N],fs,T;
       int   n,xd[N];
       fs = 1000.0;
       T  = 1/fs;
       for(n=0;n<N;n++)
       {
	       x[n] = xa(n*T);
	       xd[n] = 255*x[n];
	       printf("  x[%d]=%.4f  xd[%d]=%x\n",n,x[n],n,xd[n]);
	       getch();
       }
       getch();
}