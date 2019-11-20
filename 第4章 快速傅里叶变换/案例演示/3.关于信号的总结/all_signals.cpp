#include"graphics.h"
#include<math.h>
#include"show.h"

struct Complex
{
    float r;
    float i;
};

#define   Pi  3.1415926


float  xa(float t)
{
    return ( (1+cos(2*Pi*100*t))*cos(2*Pi*600*t) );
	//return(1.0);
}


struct Complex DTFT(float x[],int N,float w)
{
   int n;
   struct Complex Xe_jw;
   Xe_jw.r = 0;
   Xe_jw.i = 0;
   for(n=0;n<N;n++)
   {
      Xe_jw.r += x[n]*cos(-w*n);
      Xe_jw.i += x[n]*sin(-w*n);
   }
   return Xe_jw;
}

struct Complex DFT(float x[],int N,int M,int k)
{
      int n;
      float WM;
      struct Complex X_k;

      WM = 2*Pi/M;
      X_k.r  =  0.0  ;
      X_k.i  =  0.0  ;
      for(n=0;n<N;n++)
      {
	    X_k.r +=  x[n]*cos(-WM*k*n);
	    X_k.i +=  x[n]*sin(-WM*k*n);
      }
      return X_k;
}

//--------------------------------------------------------------------------
// 分析过程
//---------------------------------------------------------------------------
void main()
{
  int i,k,n,N,M;
  float x[1024],t,w,mag_w,mag_k,fs,T;
  struct Complex Xe_jw,X_k;
   
  show1();
  
  //连续时间信号xa(t)
  moveto(10,80-20*xa(-0.015));
  for(i=0,t=-0.015; t<0.015; t=t+0.00005,i++)
      lineto(10+i,80-20*xa(t));
  
  show2();
 
  //离散时间信号x(n),长度为N
  fs = 2000.0;
  T  = 1/fs;
  N  = 20;
  for(n=0;n<N;n++)
  {    
	  x[n] = xa(n*T);
      line(310+n*(T/0.00005),220,310+n*(T/0.00005),220-20*x[n]);
  }
  
  show3();
    
 //连续的频率信号Xe(jw)
   for(i=0,w=-3*Pi;w<3*Pi;w=w+0.01*Pi,i++)
  {
     Xe_jw  =  DTFT(x,N,w);
     mag_w  =  sqrt(Xe_jw.r*Xe_jw.r+Xe_jw.i*Xe_jw.i);

     if(i==0) 
		 moveto(10+i,350-150*mag_w/N);
     else
		 lineto(10+i,350-150*mag_w/N);
  }

  show4();
  
  //离散的频率信号X(k)，长度为M
  M = 20;
  for(k=0;k<M;k++)
  {
       X_k   = DFT(x,N,M,k);
       mag_k = sqrt(X_k.r*X_k.r + X_k.i*X_k.i);
       line(310+k*(2*Pi/M)/(0.01*Pi),440,310+k*(2*Pi/M)/(0.01*Pi),440-150*mag_k/N);
  }
  
  show5();
  
}

