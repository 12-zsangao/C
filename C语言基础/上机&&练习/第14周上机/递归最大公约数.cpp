#include<stdio.h>
int main()
{
	int GCD(int m,int n);
	int m,n;
	scanf("%d %d",&m,&n);
	 printf("The greatest common divisor is %d",GCD(m,n));
 } 
 //����ݹ麯������m,n�����Լ�� 
int GCD(int m,int n)
{
	int r;
	r=m%n;
	if(r!=0)
	GCD(n,r);
	else
	return n;
}
