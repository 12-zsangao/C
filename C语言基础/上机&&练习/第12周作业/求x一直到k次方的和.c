#include<stdio.h>
int main()
{
	int Ming(int a,int n);
	int x,k;
	scanf("%d,%d",&x,&k);
	printf("%d",Ming(x,k)); 
	return 0;
}
int Ming(int a,int n)
{
	int i,ming=1,sum=0;
	for(i=1;i<=n;i++)
		{
		ming=ming*a;
		sum+=ming;
		}
	return(sum);
}
