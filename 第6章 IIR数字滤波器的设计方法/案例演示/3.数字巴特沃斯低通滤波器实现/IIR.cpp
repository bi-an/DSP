#include"IIR.h"

/*  
                  一个二阶基本形式
     y(n) + a1y(n-1) + a2y(n-2)  = b0x(n) + b1x(n-1) +b2x(n-2)
     
	   y(n) = b0x(n) + b1x(n-1) +b2x(n-2) -a1y(n-1) -a2y(n-2)
*/


/* y(n)-1.297y(n-1)+0.6949y(n-2) = 0.2871x(n)-0.4466x(n-1) */

float digital_system_1(float x)
{
    static float x_2=0,x_1=0,y_1=0,y_2=0;
    float  y;

	float  b0 = 0.2871;
	float  b1 = -0.4466;
	float  b2 = 0;
	float  a1 = -1.297;
	float  a2 = 0.6949;

	y   = b0 * x + b1 * x_1 + b2 * x_2 - a1 * y_1 - a2 * y_2;
    y_2 = y_1;
	y_1 = y;
    x_2 = x_1;
	x_1 = x;
    return(y);
}

/* y(n)-1.0691y(n-1)+0.3699y(n-2) = -2.1428x(n)+1.4540x(n-1) */

float digital_system_2(float x)
{
    static float x_2=0,x_1=0,y_1=0,y_2=0;
    float  y;

	float  b0 = -2.1428;
	float  b1 = 1.1454;
	float  b2 = 0;
	float  a1 = -1.0691;
	float  a2 = 0.3699;

	y   = b0 * x + b1 * x_1 + b2 * x_2 - a1 * y_1 - a2 * y_2;
    y_2 = y_1;
	y_1 = y;
	x_2 = x_1;
	x_1 = x;
    return(y);
}


/* y(n)-0.9972y(n-1)+0.2570y(n-2) = 1.8558x(n)-0.6304x(n-1) */
float digital_system_3(float x)
{
    static float x_2=0,x_1=0,y_1=0,y_2=0;
    float  y;

	float  b0 = 1.8558;
	float  b1 = -0.6304;
	float  b2 = 0;
	float  a1 = -0.9972;
	float  a2 = 0.2570;

	y   = b0 * x + b1 * x_1 + b2 * x_2 - a1 * y_1 - a2 * y_2;
    y_2 = y_1;
	y_1 = y;
	x_2 = x_1;
	x_1 = x;

	return(y);
}

//由3个子系统并联后组成一个大系统

float Digital_System(float x)
{
     float y;
	 y = digital_system_1(x) +  digital_system_2(x) + digital_system_3(x);
	 return(y);
}