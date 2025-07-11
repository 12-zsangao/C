#include<stdio.h>
int main()
{
	//printf("输入2个大于100且小于1000的正整数m,n	&&m<n)
	int m,n,c=0,i;
	scanf("%d,%d",&m,&n);
	for(i=m+1;i<n;i++)
		{	
			if(i/100==i%10)
			{
			printf("%d\n",i);
			c=1;
			}
		}
		if(c==0)
		printf("can not find!");
	return 0;
}
