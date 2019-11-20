#include"graphics.h"
#include<math.h>
#include<conio.h>

#define   Pi  3.1415926

#define   N    50

struct Complex
{
   float r;
   float i;
};


float  xa(float t)
{
    return ( cos(2*Pi*100*t) + 2*cos(2*Pi*300*t) );
}


void init()
{
  int driver=VGA,mode=VGAHI;
  initgraph(&driver,&mode,"");
  setcolor(WHITE);
  line(310,150,310,450);
  line(10,400,610,400);
  setcolor(YELLOW);
  moveto(10,400);
}


void main()
{
  int i=0,n;
  float x[N],fs,T,w,F_w;
  struct Complex Xe_jw;

  
  init();

  fs = 1000.0;
  T  = 1/fs;
 for(n=0;n<N;n++)
       x[n] = xa(n*T);

  for( w=-3*Pi; w<=3*Pi; w=w+0.01*Pi,i++)
  {
       Xe_jw.r = 0;
       Xe_jw.i = 0;
       for(n=0;n<N;n++)
	   {
          Xe_jw.r += x[n]*cos(-w*n);
          Xe_jw.i += x[n]*sin(-w*n);
	   }
       F_w   = sqrt(Xe_jw.r * Xe_jw.r + Xe_jw.i * Xe_jw.i );
     
	 if(w>=-Pi&&w<=Pi)
		 setcolor(WHITE);
	 else
		 setcolor(YELLOW);
	 
	 lineto(10+i,400-2*F_w);
  }
 
  getch();
  closegraph();
}
