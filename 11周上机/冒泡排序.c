#include<stdio.h>
int main()
{
	int a[10],i,j,n=10,temp;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++) //最大数被移到最右侧 
			if(a[j+1]<a[j])
			temp=a[j],a[j]=a[j+1],a[j+1]=temp;
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}
