#include"graphics.h"
#include<math.h>
#include<conio.h>

#define Pi 3.1415926

float voice(float t)
{
     return( cos(2*Pi*500*t) );
}

float noise(float t)
{
     return( 2*rand()/32767.0 );
}

float receiving(float t)
{
    return( voice(t) + noise(t) );
}

main()
{
  int i,driver=VGA,mode=VGAHI;
  float t;

  initgraph(&driver,&mode,"");bar(0,0,639,479);
  setbkcolor(WHITE);
  setcolor(BLUE);

  moveto(10,75+30*voice(0) );
  for(i=0,t=0;t<0.03;t=t+0.00005,i++)
    lineto(10+i,75+30*voice(t));
  getch();

  moveto(10,150+30*noise(0));
  for(i=0,t=0;t<0.03;t=t+0.00005,i++)
     lineto(10+i,150 + 30*noise(t) );
  getch();


  setcolor(RED);
  moveto(10,300+30 * receiving(0) );
  for(i=0,t=0;t<0.03;t=t+0.00005,i++)
     lineto(10+i,300 + 30 * receiving(t) );
  getch();

  closegraph();
}
