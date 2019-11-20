#include<stdio.h>
#include<conio.h>

int T(int x)
{
   static int y_1 = 0 ;
   int y;
   y      =  x + y_1;
   y_1    =  y;
   return(y);
}

void main()
{
  int n,x,y;
  for(n=0;n<20;n++)
  {
     if( n < 10 )
	      x = n ;
	 else
		  x = 0 ;

	 y = T(x);
  
     printf(" x[%2d] = %d   y[%2d]=%d\n",n,x,n,y);
     getch();
  }
}
