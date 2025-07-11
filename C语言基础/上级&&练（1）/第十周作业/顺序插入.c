#include<stdio.h>
int main()			/*≤Â»Î≥Ã–Ú*/ 
{
	int a[11]={12,30,48,60,68,87,91,95,97,99};
	int x,i,p,n;
	scanf("%d",&x);
	p=0,n=9;
	while(a[p]<x&&p<=n)
		p++;
	for(i=n;i>=p;i--)
		a[i+1]=a[i];
	a[p]=x;
	for(i=0;i<=n+1;i++)
		printf("%d ",a[i]);
	return 0;	
 } 
