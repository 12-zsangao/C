#include<stdio.h>
int main()
{
	void f(int x[],int n);
	int a[10],i,n=10;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
		f(a,n);
		return 0;
 } 
 void f(int a[],int d)
 {
 	int i,j,b=0,c=9,min=0,max=9,t1,t2;
 	for(i=1;i<10;i++)
 	{
	 if(a[i]<a[min])
	 {
	 	min=i;
	 	b=i;
	 }
	 }
	 for(j=0;j<9;j++)
	 {
	 if(a[j]>a[max])
	 {
	 	max=j;
	 	c=j;
	 }
	 }
	 t1=a[b];
	a[b]=a[0];
	a[0]=t1;
	t2=a[c];
	a[c]=a[9];
	a[9]=t2;
	 for(i=0;i<10;i++)
	 printf("%d ",a[i]);
 
 }
