#include<stdio.h>
#include<math.h>


//先定义方程的函数
double f(double x)
{
	return x * x * x - 5 * x * x + 16 * x - 80;
 } 
 //在定义弦截法求方程的根的函数
 double root(double x1,double x2)
 {
 	double x,y,y1,y2;
 	y1 = f(x1);
 	y2 = f(x2);
 	do{
 		x = x2 - y2 * (x2 - x1) / (y2 - y1);
 		y = f(x);
 		if(y * y1 > 0)
 		{
 			x1 = x;
 			y1 = y;
		 }
		 else 
		 {
		 	x2= x;
		 	y2 = y;
		 }
	 }while(fabs(y)>0.0001);
	 return x;
  } 



int main()
{
	double x1,x2;
	scanf("%lf,%lf",&x1,&x2);
	printf("%.3lf",root(x1,x2));
	return 0;
}

