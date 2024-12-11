#include<stdio.h>
int main()
{
	int a,b,c,i,m;
	for(i=100;i<1000&&i>=100;i++)
		{
		a=i%10,m=i/10;
		b=m%10,m/=10;
		c=m%10;
		if(i==a*a*a+b*b*b+c*c*c)
		printf("%d\n\n",i);
		}
	return 0;
}
