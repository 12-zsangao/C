#include<stdio.h>
int main()
{
	
	
	int a[3][3],i,j,s1,s2;
	for(i=0;i<3;i++)
		{ 
		for(j=0;j<3;j++)
		scanf("%d",&a[i][j]);
		
		}
		s2=a[0][2]+a[1][1]+a[2][0];
		s1=a[0][0]+a[1][1]+a[2][2];
		printf("s1=%d,s2=%d",s1,s2);
		return 0;
}

	

