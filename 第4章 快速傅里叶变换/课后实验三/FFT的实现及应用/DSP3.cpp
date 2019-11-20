#include<math.h>
#include<stdio.h>
#include<conio.h>

#define   Pi  3.1415926      

struct Complex
{
	       float real;
	       float imag;
 } Complex ;

//两个复数乘法
struct Complex EE(struct Complex c1,struct Complex c2)
{
    struct Complex c3;
    c3.real =  c1.real*c2.real  - c1.imag*c2.imag;
    c3.imag =  c1.real*c2.imag  + c1.imag*c2.real;
    return(c3);
}

/*----------------------------------------------
       基2-FFT算法
 ----------------------------------------------*/
void FFT(struct Complex *xin,int N)
{
          int f,m,LH,nm,i,k,j,L;
          double p , ps ;
          int le,B,ip;
	      struct Complex w,t;
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

/*---------------------------------------------------
      待分析的模拟信号
----------------------------------------------------*/
float xa(float t)
{
   float A1,f1,fai1,A2,f2,fai2;
   f1 = 100; A1 = 2.0; fai1 = Pi/4;
   f2 = 200; A2 = 1.0; fai2 = -Pi/4;

   return( A1*cos(2*Pi*f1*t+fai1) + A2*cos(2*Pi*f2*t+fai2) );
}

/*------------------------------------------------------------------------------------------
                   测试代码
--------------------------------------------------------------------------------------------*/
void main()
{
	int n,k,N;
	float fs,T;
	struct Complex x[5000];

    FILE *f;
	f =fopen("result.txt","w");
	         
	fs = 20480;T  = 1/fs ;
    N  = 1024 ;
	     
	for(n=0;n<N;n++)
	{
	    x[n].real = xa(n*T);
		x[n].imag = 0;
	}

	 FFT(x,N);

	 fprintf(f,"      %d点快速傅里叶变换结果\n",N);
     for(k=0;k<N;k++)
		fprintf(f,"X[%4d] = %10.2f   +   %10.2fj\n",k,x[k].real,x[k].imag);
     
	 fclose(f);
}