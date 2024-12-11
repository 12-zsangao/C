#include<stdio.h>
#include<math.h>
int main()
{
	double Pn_(int n,double x);
	int n;
	double x;
	scanf("%d,%lf",&n,&x);
	printf("%.2lf",Pn_(n,x));
	return 0;  
}
double Pn_(int n,double x)
{
	double pn;
	if(n==0)
	{
	pn=1.00;
	}
	if(n==1)
	{
	pn=x;
	}
	if(n>=2)
	pn=((2*n-1)*x*Pn_(n-1,x)-(n-1)*Pn_(n-2,x))/n;
	return pn;
 } 
