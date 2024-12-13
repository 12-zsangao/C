#include<stdio.h>
int main()
{
	char a[]={1,2,3,4,5,6,7,8,9,10,11,12};
	int m;
	scanf("%d",&m); 
	char *p[12]={"January","February","March","April","May","June","July","August","Septembe","October","NovemberDecember "}; 
	
	if(m>0&&m<13)
	{
		puts(p[m-1]);
	}
	else
	printf("illegal month");
	return 0;
}
