#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int j;	
	gets(a);
	printf("%s\n",a);
	for(j=0;a[j]!='\0';j++)
		{
		if(a[j]>='a'&&a[j]<='z')
			a[j]=219-a[j];
		if(a[j]>='A'&&a[j]<='Z')
			a[j]=155-a[j];
		}
		printf("%s",a);
	return 0;
} 
