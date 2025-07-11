#include<stdio.h>
int main()
{
	void alter(int *p,int n);
	int a[3][3],i,j,n=3;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++) 
		scanf("%d",&a[i][j]);
	}
	printf("\n\n");
	int (*x)[3]=a; 
	alter(x,n);
	return 0;
 } 
 
 void alter(int *p,int n)
 {
 	int b[3][3],i,j;
 for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
 	b[j][i]=*(*(p+i)+j);
 }
	for(i=0;i<n;i++)
	{
		
		for(j=0;j<n;j++) 
		{
		printf("%d ",b[i][j]);
		if(j==2)
		printf("\n\n");
		} 
 	}
}
