#include<stdio.h>
int main()
{
	void prime(int f);
	int a;
	scanf("%d",&a);
	prime(a);
	return 0;
}
void prime(int f)
{
int i,c;
if(f==1||f==2||f==3)
		printf("%d is a prime.",f);
	else if(f>3)
	{
		c=1;
	for(i=2;i<f;i++)
		{
		if(f%i==0) c=0;
		}
	if(c==0)
		printf("%d is not a prime.",f);
	else
		printf("%d is a prime.",f);
	}
}
