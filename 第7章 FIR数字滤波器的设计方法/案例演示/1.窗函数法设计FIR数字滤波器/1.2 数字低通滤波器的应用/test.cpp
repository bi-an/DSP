#include"graphics.h"
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"fir.h"

void show1(int i,float f1,float f2);
void show2(float fc);
void show3();



/*  测试代码  */

main()
{
  int driver=VGA,mode=VGAHI,n,N;
  float x1[300],x2[300],x[300],y[300],h[200];
  float f1,f2,fs,T,fc,wc;
  


  initgraph(&driver,&mode,"");setcolor(WHITE);
  
  fs = 10000;
  T  = 1/fs;
  f1 = 500;
  f2 = 2000;
  
  for(n=0;n<300;n++)
  {
      x1[n] = cos(2*Pi*f1*n*T);  line(10+n*2,50,10+n*2,50-25*x1[n]);
  }
  show1(0,f1,f2);

  for(n=0;n<300;n++)
  {
      x2[n] = cos(2*Pi*f2*n*T);  line(10+n*2,140,10+n*2,140-25*x2[n]);
  }
  show1(1,f1,f2);

  for(n=0;n<300;n++)
  {
       x[n] = x1[n] + x2[n] ;    line(10+n*2,260,10+n*2,260-25*x[n]);
  }
  show1(2,f1,f2); 
 
  outtextxy(100,320,"fc="); scanf("%f",&fc);
  wc = 2*Pi*fc*T ;
  N  = 33;
  digital_system_design(h,N,wc);
  for(n=0;n<N;n++)
      line(10+n*2,360,10+n*2,360-150*h[n]);
 
   show2(fc);
 
 
  for(n=0;n<300;n++)
  {
	  y[n] = digital_system(h,N,x[n]);     line(10+n*2,420,10+n*2,420-25*y[n]);
  }
  show3();
}


//-----------------------------------------------------------------------------------------------------------------------------------------

void show1(int i,float f1,float f2)
{
   char str[50];
   if(i==0)
   {sprintf(str,"             %.1fHz digital signal",f1); outtextxy(100,1,str);}                            //显示x1(n)序列信息
   else if(i==1)
   {sprintf(str,"             %.1fHz digital signal",f2); outtextxy(120,90,str);}                          //显示x2(n)序列信息
   else if(i==2)
   {sprintf(str,"input digital signal: x[n]:%.1fHz+%.1fHz",f1,f2); outtextxy(100,180,str);}                 //显示x(n)序列信息
   getch();
}



void show2(float fc)
{
   char str[50];
	sprintf(str,"%.2f Hz,digital system h[n]",fc);outtextxy(120,320,str);
   getch();
}

void show3()
{
   char str[50];
   outtextxy(200,350,"output digital signal: y[n]");
   getch();
   closegraph();
}