#include<stdio.h>
int main()
{
	//printf("����2������100��С��1000��������m,n	&&m<n)
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
