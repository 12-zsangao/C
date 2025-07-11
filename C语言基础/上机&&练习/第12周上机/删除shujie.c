#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	gets(str);
	int i,j;
	for(i=0;i<20;i++)
		if(str[i]==' ')
		{
		for(j=i;j<20;j++)
			str[j]=str[j+1];
		}
	printf("The new string is: ");
	puts(str);
	return 0;
}
