
/**********************FFT program*********************/
/*基2-FFT算法*/
#include "math.h"
#include "stdio.h"
#define Pi 3.1415926

struct compx
{
  double real;
  double imag;
} compx ;


struct compx EE(struct compx b1,struct compx b2)
{
   struct compx b3;
   b3.real=b1.real*b2.real-b1.imag*b2.imag;
   b3.imag=b1.real*b2.imag+b1.imag*b2.real;
   return(b3);
}

void FFT(struct compx *xin,int N)
{
   int f,m,LH,nm,i,k,j,L;
   double p , ps ;
   int le,B,ip;
   struct compx w,t;
   LH=N/2;
   f=N;

   for(m=1;(f=f/2)!=1;m++){;}
   nm=N-2;
   j=N/2;
   /*变址运算*/
   for(i=1;i<=nm;i++)
   {
     if(i<j){t=xin[j];xin[j]=xin[i];xin[i]=t;}
     k=LH;
     while(j>=k){j=j-k;k=k/2;}
     j=j+k;
   }


   for(L=1;L<=m;L++)
   {
	   le=pow(2,L);
	   B=le/2;
	   for(j=0;j<=B-1;j++)
 	   {
  	   p=pow(2,m-L)*j;
	     ps=2*Pi/N*p;
	     w.real=cos(ps);
 	     w.imag=-sin(ps);
	     for(i=j;i<=N-1;i=i+le)
 	     {
 	      ip=i+B;
	      t=EE(xin[ip],w);
 	      xin[ip].real=xin[i].real-t.real;
   	      xin[ip].imag=xin[i].imag-t.imag;
  	      xin[i].real=xin[i].real+t.real;
 	      xin[i].imag=xin[i].imag+t.imag;
	    }
	  }
  }
}


/*****************test code********************/
float xa(float t)
{
   return ( (1+cos(2*Pi*100*t))*cos(2*Pi*600*t) );
}

void main()
{
   struct compx x[16];
   float  fs,T;
   int    n,k,N;
   
   N  = 16;
   fs = 1600.0;
   T = 1.0/fs;
   
   for(n=0;n<N;n++)
   {
      x[n].real  = xa(n*T);
      x[n].imag  = 0;
   }

   FFT(x,N);

   for(k=0;k<N;k++)
      printf("  k=%2d,X[%2d]=%8.4f + j%8.4f\n",k,k,x[k].real,x[k].imag);
}
