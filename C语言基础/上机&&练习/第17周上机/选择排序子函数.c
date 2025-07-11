#include<stdio.h>
int main()
{
	void sort(int b[],int n); 
	int a[10],i,n=10;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	sort(a,n);
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
	return 0;
}

void sort(int b[],int n)
{
	int temp,i,j;
	for(i=0;i<9;i++)
	{
		//int index = i;
		for(j=i+1;j<10;j++)
		{
			if(b[i]>b[j])
			{
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
}
