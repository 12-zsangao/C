#include<stdio.h>
int main ()
{
	int a[5],i=0,j=1,max,p;
	for(;i<5;i++)
		scanf("%d",&a[i]);
	max=a[j-1];
	for(;j<5;j++)
		{
		if(a[j]>max) 
			{
			max=a[j];
			p=j;
			}
		}
		printf("max=%d,p=%d",max,p);
	return 0;
}
