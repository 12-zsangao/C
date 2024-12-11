#include<stdio.h>
int main()
{
	int b=1,i=2,j=1;
	for(;i<=10000;i++)
    {
    	b=1;
    	for(j=2;j<i;j++)
    	{
			if(i%j==0)
				b+=j;
		}
			if(b==i)
			{
			printf("%d its fastors are 1 ",b);
			for(j=2;j<i;j++)
			if(i%j==0)
				printf("%d ",j);
			printf("\n\n"); 
			}
	}
	return 0; 
}
