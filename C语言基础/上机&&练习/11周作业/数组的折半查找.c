#include<stdio.h>
int main()
{
	int a[15]={1,4,9,13,21,34,55,89,144,233,377,570,671,703,812};
	int b,m=15,i;
	scanf("%d",&b);
	if(b==a[7])
	m=7;
    else if(b<a[7])
		{
			for(i=0;i<7;i++)
			{
				if(b==a[i])
				m=i;
			}
		}
	else if(b>a[7])
			{
			for(i=8;i<15;i++)
			{
				if(b==a[i])
				m=i;
			}
		    }
	if(m==15)
	printf("%d is not inside this array.",b);
	else
	printf("The position of %d is at (%d).",b,m);
			
	
	
}
