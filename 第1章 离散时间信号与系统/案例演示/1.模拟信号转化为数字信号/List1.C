    #include<math.h>
    #include<stdio.h>

    #define Pi 3.1415926
    #define N  20
    
    float xa1(float t)
	{
	     return( 0.5 * sin(2*Pi*100*t) ) ;   // Vpp = 1V , f = 100Hz的正弦波，信号幅值介于-0.5V -- 0.5V
	}
    
	float xa2(float t)
    {
	     return ( xa1(t) + 0.5  );       //加上直流偏置，直流偏置电压0.5V,信号幅值介于0V --1V
	}

	float xa3(float t)
	{
	     return( 5*xa2(t) );            //将xa2(t)放大5倍，信号幅值介于0V -- 5V
	}

    unsigned int ADC(int n,float fs,int bits)
	{
	    unsigned int data;
		float  q,T,y;
        T = 1/fs;
		q = 5.0/pow(2,bits);         //量化单位
		y = xa3(n*T);
        data =  (unsigned int)( y/q + 0.5) ; //四舍五入的量化
	    return(data);
	}
	  
    float Convert(unsigned int data,int bits)    //从采集到的数字信号中计算出对应输入模拟信号的电压
	{
	     float ya,q;
		 q = 5.0/pow(2,bits);
		 ya  = data * q /5 - 0.5   ;     //AD转换的满量程电压为5V，AD转位位数为bits位
	     return (ya);
	}

	void main()
    {
       float ya,fs = 1000;
	   float T;
	   unsigned int data,ADC_bits = 8;
	   int n;
	    T = 1/fs;
	   printf("  采样点     xa1(t)      xa2(t)         xa3(t)       ADC结果    LCD显示电压\n");
	   for(n=0;n<N;n++)
	   {
		   data = ADC(n,fs,ADC_bits);
           ya = Convert(data,ADC_bits);
		   printf("   n=%2d   Vxa1=%6.3f  Vxa2=%6.3f   Vxa3=%6.3f  data=%5xH   Vya=%6.3f \n",n,xa1(n*T),xa2(n*T),xa3(n*T),data,ya );
           getchar();       
	   }
	}
