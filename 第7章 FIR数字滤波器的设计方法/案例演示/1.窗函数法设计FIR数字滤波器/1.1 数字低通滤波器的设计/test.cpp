#include"graphics.h"
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

struct Complex
{
   float r;
   float i;
};

#define Pi     3.1415926

/*     采用窗函数法设计FIR数字滤波器     */

float  w(int n,int N)
{
    return ( 1 );                                       //矩形窗 
    //return( 0.54 - 0.46*cos( (2*Pi*n)/(N-1) )  );     //海明窗
}

void  digital_system_design(float h[],int N,float wc)
{
     int n;
     for(n=0;n<N;n++)
     {
	    if(n==(N-1)/2)
	        h[n] = wc/Pi * w(n,N);
	    else
	       h[n] = sin( wc* ( n-(N-1)/2 ) )/(Pi*(n-(N-1)/2)) *w(n,N);
     }
}

struct Complex DTFT(float w,float h[],int N)
{
    struct Complex He_jw;   
	int n;
	He_jw.r = 0;
    He_jw.i = 0;
    for(n=0;n<N;n++)
	{
        He_jw.r += h[n]*cos(-w*n);
        He_jw.i += h[n]*sin(-w*n);
	}
	return He_jw;
}


/*  测试代码  */

void main()
{
  
  int i,driver=VGA,mode=VGAHI,n,N;
  float f,w, fs=10000,T,fc,wc,F_w;
  float h[200];
  char str[50];
  struct Complex He_jw;
  T = 1/fs;

  initgraph(&driver,&mode,"");setbkcolor(WHITE); bar(0,0,639,479);setcolor(BLACK);
  
  fc = 2000;
  sprintf(str,"fc = %.2f Hz ,fs = %.2fHz, digital system h[n]",fc,fs);outtextxy(120,10,str);
  
  wc = 2*Pi*fc*T ;
  N  = 33;
  digital_system_design(h,N,wc);               //通过窗函数法得到一个数字滤波器h[n]
  for(n=0;n<N;n++)
     line(100+n*4,100,100+n*4,100-150*h[n]);
  getch();

  //对h(n)作序列的傅里叶变换，得到H(ejw)，作出|H(ejw)|的曲线
  for( w=-Pi,i=0; w<=Pi; w=w+0.004*Pi,i++)
  {
      He_jw  =  DTFT(w,h,N);
       F_w   =  sqrt(He_jw.r * He_jw.r + He_jw.i * He_jw.i );
     
	 if(i==0)
		 moveto(50+i,400-250*F_w);
	 else
		 lineto(50+i,400-250*F_w);
  }

  //----------------------------划刻度，显示相关信息-------------------------
  outtextxy(300,100,"|H(ejw)|");  getch();
  setcolor(GREEN);
  for( w=0,i=0; w<=Pi; w=w+0.004*Pi,i++)
  {
      if(i%5==0)
		  line(300+i,120,300+i,360);
      if(i%50==0)
		   line(300+i,110,300+i,420);
  }
  for(i=1;i<=5;i++)
  {
      f = fs/10 * i;
	  sprintf(str,"%5.0fHz",f);
	  outtextxy(260+i*55,430,str);
  }
  getch();
  
  closegraph();
}
