#include<stdio.h>
int main()
{
	double a=100,t,s1=0,h,s2;
	int i=0;
	for(;i<10;i++)
	{
		t=a;
		a=a/2;
		s1+=t+a;
		h=a;
	}
	s2=s1-h;
	printf("s=%f,h=%f",s2,h); 
	return 0;
 } 
