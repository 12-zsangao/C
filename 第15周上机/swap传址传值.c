#include<stdio.h>
/*#define
int SWAP(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}*/
int SWAP(int *m,int *n)
{
	int temp;
	temp=*m;
	*m=*n;
	*n=temp;
}
int swapValue(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int swapPointer(int *m,int *n)
{
	int temp;
	temp=*m;
	*m=*n;
	*n=temp;
}
int main()
{
	int a,b;
	int *p=&a,*q=&b;
	scanf("%d,%d",&a,&b);
	SWAP(p,q);
	printf("%Using Macro definition: a=%d,b=%d\n",a,b);
	swapValue(a,b);
	printf("Call by Value: a=%d,b=%d\n",a,b);
	swapPointer(p,q); 
	printf("Call by Address: a=%d,b=%d\n",a,b); 
	return 0;
}  
