#include<stdio.h>
int main()
{
	float a,b;
	scanf("%f %f",&a,&b); 
	float *p;
	if(a>b)
	{
		p=&a;
		*p=*p+10;
	}
	else 
	{
		p=&b;
		*p=*p+10;
	}
	printf("%.0f",*p);
	return 0;
 } 
