#include<stdio.h>
int main()
{
	int a,b;	//a������ݣ�b�����·�
	scanf("%d %d",&a,&b);
	if(a%4==0&&a%100!=0||a%400==0)
		{
		if(b==2) printf("%d.%d has 29 days",a,b);
			else
			{
				if(b==4||b==6||b==9||b==11) 
					printf("%d.%d has 30 days",a,b);
					else
					 printf("%d.%d has 31 days",a,b);
			}
		}
	else 
		if(b==2) printf("%d.%d has 28 days",a,b);
			else 
			{
			 if(b==4||b==6||b==9||b==11) 
				printf("%d.%d has 30 days",a,b);
				else printf("%d.%d has 31 days",a,b);
			}
	return 0; 
}
