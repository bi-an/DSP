#include"graphics.h"
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

#define Pi     3.1415926
#define fs 20000.0
#define T  (1.0/fs)
#define N1 300
#define N2 100

float x[N1],h[N2],y[N1+N2-1];


float xa(float t,float f)
{
    return( cos(2*Pi*f*t) );
}


float  w(int n)
{
      return( 1 );                                       //¾ØÐÎ´°
    
	  //return( 0.54 - 0.46*cos( (2*Pi*n)/(N2-1) )  );   //º£Ã÷´°
}


void LPF(float h[],int N)
{
     int n;
     float wc,Low_F = 1000.0;
     wc = 2*Pi*Low_F*T;
     for(n=0;n<N;n++)
     {
	 if(n==(N-1)/2)
	     h[n] = wc/Pi * w(n);
	 else
	     h[n] = sin( wc* ( n-(N-1)/2 ) )/(Pi*(n-(N-1)/2)) *w(n);
     }
}

float Juanjihe(float xn)
{
    static float x[N2]={0};
    int n;
    float y=0;

    for(n=N2-1;n>=1;n--)
	x[n] = x[n-1];
    x[0] = xn;

    for(n=0;n<=N2-1;n++)
	y += x[n]*h[n];

    return(y);
}




main()
{
  int driver=VGA,mode=VGAHI;
  int n;
  float f;
  char str[30];

  initgraph(&driver,&mode,"");
  LPF(h,N2);
  setcolor(WHITE);
  outtextxy(10,1,"    fs=20kHz,Input frequence of xa(t): ");scanf("%f",&f);sprintf(str,"%.2f Hz",f);outtextxy(250,1,str); 
  for(n=0;n<N1;n++)
  {
      x[n] = xa(n*T,f);
      moveto(n*2,120);
      lineto(n*2,120-100*x[n]);
  }
  setcolor(YELLOW);
   outtextxy(1,200,"Output Signal");
  for(n=0;n<N1;n++)
  {
     y[n] = Juanjihe(x[n]);
     moveto(n*2,350);
     lineto(n*2,350-100*y[n]);
  }
  getch();
  for(n=0;n<20;n++)
  {
     if(n<=10) setcolor(RED);
     else      setcolor(GREEN);
     line(1,250+n*5,600,250+n*5);
  }
  getch();
  closegraph();
}

