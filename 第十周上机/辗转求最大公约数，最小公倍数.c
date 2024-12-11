#include<stdio.h>
int main()
{
	int m,n,r,t,a,b;
	scanf("%d,%d",&n,&m);
	a=m;
	b=n;
	r=m%n; 
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;	
	}
	t=a*b/n;
	printf("%d\n",n);
	printf("%d",t);
	return 0; 
}
