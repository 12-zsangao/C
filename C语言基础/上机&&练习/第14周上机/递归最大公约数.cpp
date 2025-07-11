#include<stdio.h>
int main()
{
	int GCD(int m,int n);
	int m,n;
	scanf("%d %d",&m,&n);
	 printf("The greatest common divisor is %d",GCD(m,n));
 } 
 //定义递归函数来求m,n的最大公约数 
int GCD(int m,int n)
{
	int r;
	r=m%n;
	if(r!=0)
	GCD(n,r);
	else
	return n;
}
