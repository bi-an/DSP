#include<math.h>
#include"fir.h"

/*     采用窗函数法设计FIR数字滤波器     */
float  w(int n,int N)
{
    return( 0.54 - 0.46*cos( (2*Pi*n)/(N-1) )  );
}

void  digital_system_design(float h[],int N,float wc)
{
     int  n;
	 int  Tao;
	 Tao  = (N-1)/2;
     for(n=0;n<N;n++)
     {
	    if( n==Tao )
	       h[n] = wc/Pi * w(n,N);
	    else
	       h[n] = sin( wc* ( n-Tao ) )/(Pi*(n-Tao)) * w(n,N);
     }
}


/* 采用横截型运算结构实现数字滤波器输入到输出的运算*/

float digital_system(float h[],int N,float x)
{
    static float x_delay[200]={0};
    int n;
    float y=0;

    for(n=N-1;n>=1;n--)
	     x_delay[n] = x_delay[n-1];
    x_delay[0] = x;

    for(n=0;n<=N-1;n++)
	    y += h[n] * x_delay[n];

    return(y);
}