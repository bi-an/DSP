#include"graphics.h"
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

#define Pi  3.1415926
#define M   500
#define N1  100
#define N2  50

float  x[M],h[M],y1[M],y2[M];
float Xr[M],Xm[M],Hr[M],Hm[M],Yr[M],Ym[M];


float T(float xn)
{
   static float x[N2] = {0};
   float y=0;
   int n;

   for(n=N2-1;n>=1;n--)
      x[n] = x[n-1];
   x[0] = xn;

   for(n=0;n<N2;n++)
      y += x[n]*h[n];

   return(y);
}
void DFT(float x[],int N,float Xr[],float Xm[])
{
  int n,k;
  float w;
  w = -1.0*2*Pi/N;
  for(k=0;k<N;k++)
  {
     Xr[k] = 0.0;
     Xm[k] = 0.0;
     for(n=0;n<N;n++)
     {
	Xr[k] += x[n]*cos(w*k*n);
	Xm[k] += x[n]*sin(w*k*n);
     }
  }
}

void IDFT(float y[],int N,float Xr[],float Xm[])
{
  int n,k;
  float w;
  w=2*Pi/N;
  for(n=0;n<N;n++)
  {
    y[n] = 0.0;
    for(k=0;k<N;k++)
      y[n] += Xr[k]*cos(w*k*n) - Xm[k]*sin(w*k*n);
    y[n] = y[n] /N;
  }
}



main()
{
  int driver=VGA,mode=VGAHI;
  int n,L;
  char buf[30];
  initgraph(&driver,&mode,"");

  
  for(n=0;n<N1;n++)
      x[n] = 1 ;
  for(n=0;n<N2;n++)
      h[n] = 1;

  /*求出两个序列的线性卷积和*/
  for(n=0;n<N1+N2-1;n++)
  {
	   y1[n] = T(x[n]);
	   moveto(100+n*3,100);
	   lineto(100+n*3,100-y1[n]);
  }
  
  
  sprintf(buf,"N1=%d,N2=%d,Please Enter L(<500):",N1,N2);outtextxy(100,120,buf);scanf("%d",&L);
  
  /*利用离散傅里叶正反变换求两个序列的圆周卷积和*/
  DFT(x,L,Xr,Xm);
  DFT(h,L,Hr,Hm);
  for(n=0;n<L;n++)
  {
     Yr[n] = Xr[n]*Hr[n] - Xm[n]*Hm[n] ;
     Ym[n] = Xr[n]*Hm[n] + Xm[n]*Hr[n] ;
  }
  IDFT(y2,L,Yr,Ym);
  setcolor(RED);
  for(n=0;n<L;n++)
  {
	moveto(100+n*3,200);
	lineto(100+n*3,200-y2[n]);
  }

  getch();
  closegraph();
}
