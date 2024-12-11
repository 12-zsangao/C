#include<stdio.h>
int main()
{
	int m,n,r;
	scanf("%d,%d",&n,&m);
	r=m%n; 
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;	
	}
	printf("%d",n);
	return 0; 
}
