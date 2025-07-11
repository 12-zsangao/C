#include<stdio.h>
int main()
{
	void HUAN(int (*p)[5],int n);
	int a[5][5];
	int i,j,n=5;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		scanf("%d",&a[i][j]);
	}
	HUAN(a,n);
	//printf("The handaled matrix is:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("%d ",a[i][j]); 
		if(j==4)
		printf("\n");
		}
	}
	return 0;
}
void HUAN(int (*p)[5],int n)
{
	int temp;
	int i=0,j=0;
	for(i;i<n;i++)
	{
		for(j;j<n;j++)
		if(*(*(p+i)+j)>*(*(p+2)+2))
		{
			temp=*(*(p+i)+j);
			*(*(p+i)+j)=*(*(p+2)+2);
			*(*(p+2)+2)=temp;
		}
	}
}
