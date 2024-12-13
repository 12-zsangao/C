#include<stdio.h>
int main()
{
	int prime(int f);
	int a;
	scanf("%d",&a);
	if(prime(a))
	printf("%d is a prime.",a);
	else
	printf("%d is not a prime.",a);
	return 0;
}
int prime(int f)
{
	int i,c;
	if(f==1||f==2||f==3)
		return 1;
	if(f>3)
	{
		c=1;
	for(i=2;i<f;i++)		//从2除到它本身减1，如果除尽就不是素数 
		{
		if(f%i==0) c=0;
		
		}
		return c;
	}
		
		
}

