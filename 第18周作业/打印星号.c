#include<stdio.h>
#include<math.h>
int main()
{
	int i,j;
	/*int n;
	scanf("%d",&n);
	后面把四改为n/2+1,3改为n/2-1*/ 
	for(i=1;i<=4;i++)
	{
		for(j=0;j<fabs(4-i);j++)
		printf(" ");
		for(j=0;j<2*i-1;j++)
		printf("*");
		for(j=0;j<fabs(4-i);j++)
		printf(" ");
		printf("\n");
	}
	for(i=3;i>=1;i--)
	{
		for(j=0;j<fabs(4-i);j++)
		printf(" ");
		for(j=0;j<2*i-1;j++)
		printf("*");
		for(j=0;j<fabs(4-i);j++)
		printf(" ");
		printf("\n");	
	}
	return 0;
}
