#include<stdio.h>
int main()
{
	int i,n;
	long long sum=0;
	scanf("%d",&n);
	long long a[n],s[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		s[i]=0;
	}
	s[0]=a[0];
	for(i=1;i<n;i++)
	s[i]+=s[i-1]+a[i];
	for(i=0;i<n-1;i++)
	{
		sum+=a[i]*(s[n-1]-s[i]);	
	}
	printf("%lld",sum);
	return 0;
 } 
