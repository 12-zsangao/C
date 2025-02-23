#include<stdio.h>
int main()
{
	int sum=0,i=1,n;
	scanf("%d",&n);
	while(i<=n)
	{
		sum+=i;
		i++;
	}
	printf("%d\n",sum);
	return 0;
}

#include<stdio.h>
int main()
{
	int sum=0,i=1,n;
	scanf("%d",&n);
	do
	{
		sum+=i;
		i++;
	}
	printf("%d\n",sum);
	return 0;
}


#include<stdio.h>
int main()
{
	int sum=0,i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	printf("%d\n",sum);
	return 0;
}
