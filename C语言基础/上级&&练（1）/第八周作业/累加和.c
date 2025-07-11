#include<stdio.h>
int main()
{
	int n,sum=0,i=0;
	scanf("%d",&n); 
	while(i<n)
	{
		i++;
		sum=sum+i;
	}
	printf("sum=%d",sum);
	return 0;
}
