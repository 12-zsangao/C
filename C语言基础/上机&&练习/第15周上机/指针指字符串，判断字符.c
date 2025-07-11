#include<stdio.h>
int main()
{
	int total=0,upper=0,lower=0,space=0,digit=0,other=0;
	char a[50];
	char *p=a;
	gets(p);
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		total++;
		if(a[i]>='A'&&a[i]<='Z') upper++;
		else if(a[i]>='a'&&a[i]<='z') lower++;
				else if(a[i]>='0'&&a[i]<='9') digit++;
				 		else if(a[i]==' ')  space++;
				 			else other++; 
	}
	printf("total:%d  upper:%d  lower:%d  space:%d  digit:%d  other:%d",total,upper,lower,space,digit,other);
	return 0;
}
