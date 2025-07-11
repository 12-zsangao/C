#include<stdio.h>
int main()
{
	int MAX2(int x,int y);
	int MAX3(int x,int y,int z);
	int a,b,c;
	scanf("%d,%d,%d",&a,&b,&c);
	printf("By MAX2, the max number is %d\n",MAX2(c,MAX2(a,b)));
	printf("By MAX3, the max number is %d\n",MAX3(a,b,c));
	return 0; 
}
int MAX2(int x,int y)
{
	if(x>y)
	return x;
	else
	return y;
 } 
int MAX3(int x,int y,int z)
{
	if(x>y&&x>z) 
	return x;
	if(y>x&&y>z)
	return y;
	if(z>x&&z>y)
	return z;
}
