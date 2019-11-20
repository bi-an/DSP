#include"graphics.h"
#include<math.h>
#include<conio.h>
#include<stdio.h>

#define Pi  3.1415926
#define   N     6

float   h[6]  = {1, 8/3, -205/12, 205/12, -8/3, -1.0 }; 

//横截型运算结构的实现
float  digital_system(float x_0)
{
    static float x_1,x_2,x_3,x_4,x_5;
    float y;
    
	x_5 = x_4;
	x_4 = x_3;
	x_3 = x_2;
	x_2 = x_1;
	x_1 = x_0;

    y = h[0]*x_0 + h[1]*x_1 + h[2]*x_2 + h[3]*x_3 + h[4]*x_4 + h[5]*x_5;
   
    return(y);
}

void show_info(float f)
{
    char str[50];
	sprintf(str," f = %.2f Hz",f);
	cleardevice();
    setcolor(YELLOW);
	line(10,270,600,270),
	line(10,430,600,430);
	outtextxy(200,200,str);
	setcolor(WHITE);
}

void delay()
{
    int i,j;
	for(i=0;i<10000;i++)
	  for(j=0;j<10000;j++)
			;
}

void main()
{
  int driver=VGA,mode=VGAHI;
  float x[150],y[150],fs,T,f;
  int n;
  
   initgraph(&driver,&mode,"");
   
   fs = 10000;               
   T  = 1/fs;
   for(f=0;f<=fs/2;f=f+100)
   {
       show_info(f);
	   for(n=0;n<150;n++)
	   {
          x[n] = cos(2*Pi*f*n*T);
          line(n*4,120,n*4,120-40*x[n]);
      
          y[n] = digital_system(x[n]);
          line(n*4,350,n*4,350-2*y[n]);
	   }
	   delay();
  }
   getch();
  closegraph();
}