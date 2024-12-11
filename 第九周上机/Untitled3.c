#include<stdio.h>
int main()
{
	int k=1,m=1,n=1,a=0,b=0;
	float c,p;
	for(;k<=100;k++)
		a+=k;
	for(;m<=50;m++)
		b+=m*m;
	for(;n<=10;n++)
		c+=1.0/n;
	p=a+b+c;
	printf("sum=%8.2f",p);
	return 0;	
}
