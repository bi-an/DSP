#include<graphics.h>
#include<math.h>
#define   Pi  3.1415926

int       N;
int       M;
float     x[1024];

float  xa(float t)
{
    return (1.0);
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

struct Complex X(int k)
{
      int n;
      float WN;
      struct Complex Xk;

      WN = 2*Pi/M;
      Xk.r  =  0.0  ;
      Xk.i  =  0.0  ;
      for(n=0;n<N;n++)
      {
	    Xk.r +=  x[n]*cos(-WN*k*n);
	    Xk.i +=  x[n]*sin(-WN*k*n);
      }
      return Xk;
}

void main()
{
  int driver=VGA,mode=VGAHI;
  int i=0,k,x0,y0,n;
  float t,w,F_w,Fk;
  struct Complex X_w,Xk;

  float fs,T;
  initgraph(&driver,&mode,"");
  setbkcolor(WHITE);
  setcolor(GREEN);
  line(20,80,610,80);
  line(310,1,310,100);
  setcolor(RED);
  for(i=0,t=0;t<0.03;t=t+0.0001,i++)
  {
    if(i==0)
	moveto(310+i,80-60*xa(t));
    else
	lineto(310+i,80-60*xa(t));
  }
  for(i=0,t=0;t>-0.03;t=t-0.0001,i--)
  {
    if(i==0)
	 moveto(310+i,80-60*xa(t));
    else
	 lineto(310+i,80-60*xa(t));
  }
  gotoxy(38,1);
  printf("xa(t)");
  gotoxy(77,6);
  printf("t");
  getch();
  fs = 1000.0;
  T  = 1/fs;
  N  = 4;
  for(n=0;n<1024;n++)
  {
  	 if(n<N)
         x[n] = xa(n*T);
     else
     	   x[n] = 0;
  }

  for(n=0;n<N;n++)
     line(310+n*(T/0.0001),180,310+n*(T/0.0001),180-60*x[n]);
    gotoxy(38,7);
  printf("x(n)");
  getch();

  setcolor(BLUE);
  for(i=0,w=-3*Pi;w<3*Pi;w=w+0.01*Pi,i++)
  {
     X_w = Xe_jw(w);
     F_w =  sqrt(X_w.r*X_w.r+X_w.i*X_w.i);

     if(i==0)
		   moveto(10+i,300-100*F_w/N);
     else
		   lineto(10+i,300-100*F_w/N);
  }
  setcolor(GREEN);
  line(310,310,310,190);
  line(10,300,600,300);
   gotoxy(38,12);
  printf("|X(ejw)|");
  gotoxy(77,20);
  printf("w");
  getch();
  setcolor(BLUE);


  M = 16;
  for(k=0;k<M;k++)
  {
       Xk = X(k);
       Fk = sqrt(Xk.r*Xk.r + Xk.i*Xk.i);
       moveto(310+k*(2*Pi/M)/(0.01*Pi),440);
       lineto(310+k*(2*Pi/M)/(0.01*Pi),440-100*Fk/N);
  }
  gotoxy(38,21);
  printf("|X(k)|");
  getch();
  closegraph();
}

