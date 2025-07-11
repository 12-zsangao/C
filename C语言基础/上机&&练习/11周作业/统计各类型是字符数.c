#include<stdio.h>
#include<string.h>
int main()
{
	char a[3][80];
	int i,j;
	int upper=0,low=0,digit=0,space=0,other=0;
	for(i=0;i<3;i++)
	gets(a[i]);
	for(i=0;i<3;i++)
		for(j=0;a[i][j]!='\0';j++) 
		{
		if(a[i][j]>='A'&&a[i][j]<='Z')	upper++;
		else if(a[i][j]>='a'&&a[i][j]<='z')	low++;
				else if(a[i][j]>=48&&a[i][j]<=56)	digit++;
					else if(a[i][j]==' ')					space++;
						else other++;
		}
		printf("upper low   digit space other\n");
		printf("%d     %d    %d     %d     %d",upper,low,digit,space,other);
	return 0;
}
   
