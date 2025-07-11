#include<stdio.h>
int main()
{
	int a[3][2]={7,12,-3,2,-1,5};
	int row,column,i,j,m=a[0][0];
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			if(a[i][j]<m)
				m=a[i][j],row=i,column=j;
	printf("min is a[%d][%d]=%d",row,column,m);
	return 0;
}
