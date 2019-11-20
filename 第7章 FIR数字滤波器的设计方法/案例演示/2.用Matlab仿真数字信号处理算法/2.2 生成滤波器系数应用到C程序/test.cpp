#include"graphics.h"
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

#define N      26
#define Pi     3.1415926

float   h[N] ={-0.008508324848002298,-0.0174207903870853,                  
 0.0035274477430436938,               
 0.012538812307535405,                
-0.019847128026137209,                
 0.0036617762097835987,               
 0.028225657013357715,                
-0.040958579103686145,                
 0.003403700220183381,                
 0.069723359247470237,                
-0.10644915130640467,                 
 0.0030904594115084283,               
 0.54871938164872636,                
 0.54871938164872636,                 
 0.0030904594115084283,              
-0.10644915130640467,                
 0.069723359247470237,                
 0.003403700220183381,                
-0.040958579103686145,                
 0.028225657013357715,                
 0.0036617762097835987,               
-0.019847128026137209,                
 0.012538812307535405,                
 0.0035274477430436938,               
-0.0174207903870853,                
-0.008508324848002298
};

/*   采用横截型运算结构实现数字滤波器输入到输出的运算*/

float Digital_System(float x)
{
    static float x_delay[N]={0};
    int n;
    float y=0;

    for(n=N-1;n>=1;n--)
	     x_delay[n] = x_delay[n-1];
    x_delay[0] = x;

    for(n=0;n<=N-1;n++)
	    y += x_delay[n]*h[n] ;

    return(y);
}  

/*  测试代码  */

main()
{
  
  int driver=VGA,mode=VGAHI,n;
  float x[300],y[300],x1[300],x2[300];
  float f1=200,f2=4000,fs=10000,T;
  char str[50];

  T = 1/fs;

  initgraph(&driver,&mode,"");setcolor(WHITE);
   
  for(n=0;n<300;n++)
  {
      x1[n] = cos(2*Pi*f1*n*T);
      moveto(10+n*2,50);lineto(10+n*2,50-25*x1[n]);
  }
  sprintf(str,"             %.1fHz digital signal",f1); outtextxy(100,1,str); getch();

 
  
  for(n=0;n<300;n++)
  {
      x2[n] = cos(2*Pi*f2*n*T);
      moveto(10+n*2,140);lineto(10+n*2,140-25*x2[n]);
  }
  sprintf(str,"             %.1fHz digital signal",f2); outtextxy(120,90,str);getch();


  for(n=0;n<300;n++)
  {
     x[n] = x1[n] + x2[n] ;
     moveto(10+n*2,260);lineto(10+n*2,260-25*x[n]);
  }
  sprintf(str,"           input digital signal: x[n]:%.1fHz+%.1fHz",f1,f2); outtextxy(100,180,str);getch();

  
  
 
  for(n=0;n<N;n++){moveto(10+n*2,360);lineto(10+n*2,360-150*h[n]);}getch();

  
  for(n=0;n<300;n++)
  {
     y[n] = Digital_System(x[n]);
     moveto(10+n*2,420);lineto(10+n*2,420-25*y[n]);
  }

  outtextxy(200,350,"output digital signal: y[n]");getch();
  
  closegraph();
}
