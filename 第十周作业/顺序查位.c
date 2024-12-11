#include<stdio.h> 
int main()
{
	int a[10]={23,56,11,87,91,35,41,44,60,6};
	int x,i=0;
	scanf("%d",&x);
	for(;i<10;i++)
		if(x==a[i]) printf("%d position is %d",x,i);
	if(x!=a[0]&&x!=a[1]&&x!=a[2]&&x!=a[3]&&x!=a[4]&&x!=a[5]&&x!=a[6]&&x!=a[7]&&x!=a[8]&&x!=a[9])
		printf("%d could not be found",x);
	return 0;
}
