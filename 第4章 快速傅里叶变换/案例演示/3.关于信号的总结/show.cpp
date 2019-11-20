#include"graphics.h"
#include<conio.h>
//-----------------------------------------------------------------------------------
//显示相关信息函数
//--------------------------------------------------------------------------------------
void show1()
{
  int driver=VGA,mode=VGAHI;
  initgraph(&driver,&mode,"");
  setbkcolor(WHITE);
  bar(0,0,639,479);
  setcolor(GREEN);
  line(20,80,610,80);
  line(310,1,310,150);
  setcolor(RED);
}

void show2()
{
  outtextxy(300,1,"xa(t)");
  outtextxy(620,75,"t");
  
  getch();
}

void show3()
{
  outtextxy(300,150,"x(n)");
  setcolor(BLUE);
  getch();
}

void show4()
{
   setcolor(GREEN);
  line(310,360,310,260);
  line(10,350,600,350);
  outtextxy(290,250,"|X(ejw)|");
  outtextxy(610,340,"w");
  getch();
  setcolor(BLUE);
}

void show5()
{
  outtextxy(300,360,"|X(k)|");
  getch();
  closegraph();
}
