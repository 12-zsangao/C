#include<stdio.h>
#include<math.h>
int main()
{
	double gen(double x);
	double a;
	scanf("%lf",&a);
	printf("%.3lf",gen(a));
	return 0; 
}
double gen(double x)
{
	double x0=x;
	double x1;
	do
	{
		x1=x0;
		x0=(x1+x/x1)/2;
	}
	while(fabs(x0-x1)>=0.00001);
	return x0;
}
