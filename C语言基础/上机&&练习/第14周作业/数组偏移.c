#include<stdio.h>
int main()
{
	void CCC(int *p,int n,int m);
	int n,m,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	CCC(a,n,m);
	return 0;
}
void CCC(int *p,int n,int m)
{
	int i,j,b[m];
	for(i=0;i<m;i++)
	b[i]=*(p+n-m+i);
	for(i=n-1;i>=m;i--)
	{
		*(p+i)=*(p+i-m);
	}
	for(i=0;i<m;i++)
	*(p+i)=b[i];
	for(i=0;i<n;i++)
	printf("%d ",*(p+i));
}

