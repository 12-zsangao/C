#include<stdio.h>
int main()
{
	void invert(int *p,int n);
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	invert(a,n); 
	return 0;
}
void invert(int *p,int n)
{
	int i,temp;
	 for(i=0;i<n;i++)
	 printf("%d ",*(p+n-i-1));
	 //可以直接倒着输出，或者也可以对称数位互换；
	 //用四种方式，形参实参是指针或数组名；
	 //这里我直接用实参数组名，形参指针。 
}

