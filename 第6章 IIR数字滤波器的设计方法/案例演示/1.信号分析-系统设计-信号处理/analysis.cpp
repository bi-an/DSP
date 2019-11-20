#include"graphics.h"
#include<conio.h>
#include<math.h>

#define   Pi  3.1415926

#define   N 100
float     x[N];

float voice(float t)
{
    return ( cos(2*Pi*500*t) );
}

float noise(float t)
{
    return( 2*rand()/32767.0 );
}

float receiving(float t)
{
    return( voice(t) + noise(t) );
}

struct Complex
{
    float r;
    float i;
};

struct Complex Xe_jw(float w)
{
   int n;
   struct Complex X_w;
   X_w.r = 0;
   X_w.i = 0;
   for(n=0;n<N;n++)
   {
      X_w.r += x[n]*cos(-w*n);
      X_w.i += x[n]*sin(-w*n);
   }
   return X_w;
}

void InitSystem()
{
  int driver = VGA,mode =VGAHI;
  initgraph(&driver,&mode,""); bar(0,0,639,479);
  setbkcolor(WHITE);
}

void show_info1()
{
  setcolor(GREEN);
  line(0,180,420,180);
  line(210,120,210,190);
  line(10,170,10,190);
  line(410,170,410,190);
  outtextxy(180,110,"|Xe(jw)|");
  outtextxy(430,180,"w");
  outtextxy(5,190,"-Pi");
  outtextxy(205,190,"0");
  outtextxy(405,190,"-Pi");
  getch();
}

void show_info2()
{
  setcolor(GREEN);
  line(0,460,420,460);
  line(210,320,210,470);
  line(10,450,10,470);
  line(410,450,410,470);
  outtextxy(180,330,"|Xe(jw)|");
  outtextxy(430,450,"w");
  outtextxy(5,465,"-Pi");
  outtextxy(205,465,"0");
  outtextxy(405,465,"-Pi");
  getch();
}

void main()
{
  int i,n;
  float t,fs,T,w,F_w;
  struct Complex X_w;

  InitSystem();

  setcolor(BLUE);
  moveto(10,30+20*voice(0));
  for(i=0,t=0;t<0.03;t=t+0.00005,i++)
     lineto(10+i,30+20*voice(t));
  getch();

  fs = 4000.0;
  T  = 1/fs;
  for(n=0;n<N;n++)
  {
      x[n] = voice(n*T);
      line(10+n*(T/0.00005),80,10+n*(T/0.00005),80+20*x[n]);
  }
  getch();
  
  setcolor(RED);
  for(i=0,w=-Pi;w<Pi;w=w+0.005*Pi,i++)
  {
     X_w = Xe_jw(w);
     F_w =  sqrt(X_w.r*X_w.r+X_w.i*X_w.i);
	 if(i==0) 
		  moveto(10+i,180-100*F_w/N);
	 else
          lineto(10+i,180-100*F_w/N);
  }
  show_info1();

  setcolor(BLUE);
  moveto(10,240 + 20 * receiving(0) );
  for(i=0,t=0;t<0.03;t=t+0.00005,i++)
      lineto(10+i,240 +10 * receiving(t) );
   getch();

  for(n=0;n<N;n++)
  {
     x[n] = receiving(n*T);
     line(10+n*(T/0.00005),300,10+n*(T/0.00005),300+10*x[n]);
  }
  getch();
  setcolor(RED);
  for(i=0,w=-Pi;w<Pi;w=w+0.005*Pi,i++)
  {
     X_w = Xe_jw(w);
     F_w =  sqrt(X_w.r*X_w.r+X_w.i*X_w.i);
	 if(i==0)
		 moveto(10+i,460-100*F_w/N);
	 else 
	    lineto(10+i,460- 100*F_w/N);
  }
  show_info2();

  closegraph();
}

