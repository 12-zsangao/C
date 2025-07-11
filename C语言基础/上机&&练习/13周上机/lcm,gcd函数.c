#include<stdio.h>
int main()
{
	int gcd(int m,int n);
	int lcm(int m,int n); 
	int m,n,temp;
	scanf("%d,%d",&m,&n);
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	printf("%d\n\n",gcd(m,n));		//gcd,lcm分别表示最大公约数，最小公倍数 
	printf("%d\n",lcm(m,n));
	return 0;
}
int gcd(int m,int n)
{
	int r;
		r=m%n;
		while(r!=0)
		{
			m=n;
			n=r;
			r=m%n;
		}
	return(n);
 } 

int lcm(int m,int n)
{
	int a;
	a=m*n/gcd(m,n);
	return(a);
}
