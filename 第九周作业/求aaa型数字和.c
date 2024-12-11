#include<stdio.h>
#include<math.h>
int main()
{
	int n,s=0,i=0,m=0,a=2;
	scanf("%d",&n);
	while(i<n)
	{
		double t=pow(10,i);
		s+=2*t;
		m+=s;
		i++;
	 } 
	 printf("sum=%d",m);
	 return 0; 
 } 
