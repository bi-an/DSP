#include<math.h>

#define Pi  3.1415926


struct Complex
{
	     float  r ;
	     float  i ;
};


float xa(float t)
{
	return( (1+cos(2*Pi*100*t)) * cos(2*Pi*600*t) );
}

void DFT(struct Complex x[],int N,struct Complex X[])
{
  int n,k;
  float WN;
  WN = -2*Pi/N;
  for(k=0;k<=N-1;k++)
  {
     X[k].r  =  0  ;
     X[k].i  =  0  ;
     for(n=0;n<=N-1;n++)
     {
	     X[k].r +=  x[n].r*cos(WN*k*n) - x[n].i*sin(WN*k*n);
	     X[k].i +=  x[n].r*sin(WN*k*n) + x[n].i*cos(WN*k*n);
     }
  }
}



main()
{
  int k,n,N;
  struct Complex x[15],X[15];
  float fs,T;

  fs  = 1500;
  N   = 15 ;
  T   = 1/fs;
  
  for(n=0;n<=N-1;n++)
  {
     x[n].r  =  xa(n*T);;            
     x[n].i  =  0       ;
  }

  for(n=0;n<=N-1;n++)
  {
    printf("n = %2d,x[%2d] = %8.3f + j%8.3f\n",n,n,x[n].r,x[n].i);
    getch();
  }
  
  DFT(x,N,X);
  
  
  for(k=0;k<=N-1;k++)
  {
    printf("\t\t\t\t\tk =%2d,X[%2d] = %8.3f + j%8.3f\n",k,k,X[k].r,X[k].i);
    getch();
  }
  
}
