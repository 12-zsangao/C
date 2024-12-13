#include<stdio.h>
#include<string.h>
int main()
{
	char a[10],b[10];
	int i,j,flag;
	gets(a);
	gets(b);
	for(i=0;a[i]!='\0';i++)
		flag=i+1;
	for(i=0;i<10;i++)
		a[flag+i]=b[i];
	puts(a);
	return 0;
 } 
