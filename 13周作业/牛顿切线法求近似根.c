#include<stdio.h>
#include<math.h>
int main()
{
	double f(double k);
	double f_(double k);
	double root(double x0); 
	double x0=1.5;
	printf("%.3lf",root(x0));
	return 0;
 } 

//定义函数f
double f(double k)
{
	return 2*k*k*k-4*k*k+3*k-6;
 } 
//定义函数f导函数F
double f_(double k)
{
	return 6*k*k-8*k+3;
 } 
//定义求接近真实根的近似根函数
double root(double x0)
{
	double x,y_,y,y0,y0_,a;
	y0=f(x0);
	y0_=f_(x0);
	do
	{
		x=x0-y0/y0_; 
		y=f(x);
		y_=f_(x);
		a=x0-x;
		x0=x;
		y0=y;
		y0_=y_;
	}
	while(fabs(a)>0.00001);
	return x;
}
  
