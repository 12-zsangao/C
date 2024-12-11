#include<stdio.h>
int main()
{
	int a[5],i,temp;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	for(i=0;i<3;i++)
		temp=a[i],
		a[i]=a[4-i],
		a[4-i]=temp;
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	return 0;
}
