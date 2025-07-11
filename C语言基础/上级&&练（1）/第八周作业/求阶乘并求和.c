#include<stdio.h>
int main()
{
	int n,j=0,i=0,a=1,y;
	int sum;
	scanf("%d",&n);
	while(i<n)
	{
		i++;
		while(j<i)
		{	
			a*=i;
			j++; 
			y=a;
		}
		sum+=y;
	}
	printf("sum=%d",sum); 
return 0;
}
