#include<stdio.h>
#include<string.h>
int main()
{
	int n=10,i,m;
	char a[10];
	gets(a);
	char *p=a;
	scanf("%d",&m);
	if(m<n)
	{
		char b[n-m+1];
		char *q=b;
		for(i=0;i<n-m+1;i++)
		{
			*(q+i)=*(p+m-1+i);
		}
		for(i=0;i<n-m+1;i++)
		printf("%c",*(q+i));
	}
	else
	printf("m needs < n");
	return 0; 
}
