#include"graphics.h"
#include<math.h>
#include<conio.h>

#define Pi  3.1415926
#define N   75

struct Complex
{
	     float  r ;
	     float  i ;
};


void DFT(struct Complex x[],struct Complex X[])
{
  int n,k;
  float WN;
  WN = -2*Pi/N;
  for(k=0;k<N;k++)
  {
     X[k].r  =  0.0  ;
     X[k].i  =  0.0  ;
     for(n=0;n<N;n++)
     {
	     X[k].r +=  x[n].r*cos(WN*k*n) - x[n].i*sin(WN*k*n);
	     X[k].i +=  x[n].r*sin(WN*k*n) + x[n].i*cos(WN*k*n);
     }
  }
}

void IDFT(struct Complex X[],struct Complex x[])
{
  int n,k;
  float WN;
  WN = 2*Pi/N;
  for(n=0;n<N;n++)
  {
     x[n].r  =  0.0  ;
     x[n].i  =  0.0  ;
     for(k=0;k<N;k++)
     {
	     x[n].r +=  X[k].r*cos(WN*k*n) - X[k].i*sin(WN*k*n);
	     x[n].i +=  X[k].r*sin(WN*k*n) + X[k].i*cos(WN*k*n);
     }
     x[n].r   =  x[n].r / N ;
     x[n].i   =  x[n].i / N ;
  }
}



void main()
{
  int n,driver=VGA,mode=VGAHI;
  struct Complex x[N],X[N],y[N];
  
  initgraph(&driver,&mode,"");
  
  for(n=0;n<N;n++)
  {
	    x[n].r  =   2*n;
        setcolor(WHITE);line(10+n*4,200,10+n*4,200-x[n].r);
	    
		x[n].i  =  150;
        setcolor(YELLOW);line(320+n*4,200,320+n*4,200-x[n].i);
  }

  getch();
  
  //X(k)=DFT(x[n])
  DFT(x,X);

  //y(n)=IDFT(X[k])
  IDFT(X,y);

  for(n=0;n<N;n++)
  {
      setcolor(WHITE);line(10+n*4,400,10+n*4,400-y[n].r);
      setcolor(YELLOW);line(320+n*4,400,320+n*4,400-y[n].i);
      
  }
  getch();
  closegraph();
}
