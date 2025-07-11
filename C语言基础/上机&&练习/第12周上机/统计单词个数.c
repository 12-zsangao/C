#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int i,j=1;
	gets(a);
	for(i=0;a[i]!='\0';i++)
		if(a[i]==' ')  j=j+1;
	printf("There are %d words.",j);
	return 0;
}
