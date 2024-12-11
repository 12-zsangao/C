#include<stdio.h>
int main()
{
	int h,place;
	scanf("%d",&h);
	int i=h;
	for(place=0;h!=0;place++)
		h/=10; 
		printf("place=%d\n\n",place);
	if(place==5)
	{
		int a,b,c,d,e;
		a=i%10,i/=10;
		b=i%10,i/=10;
		c=i%10,i/=10;
		d=i%10,i/=10;
		e=i%10,i/=10;
		printf("%d,%d,%d,%d,%d\n\n",e,d,c,b,a);
		printf("Inverted=%d%d%d%d%d",a,b,c,d,e);
	}
	if(place==4)
	{
		int a,b,c,d;
		a=i%10,i/=10;
		b=i%10,i/=10;
		c=i%10,i/=10;
		d=i%10,i/=10;
		printf("%d,%d,%d,%d\n\n",d,c,b,a);
		printf("Inverted=%d%d%d%d",a,b,c,d);
	} 
	if(place==3)
	{
		int a,b,c;
		a=i%10,i/=10;
		b=i%10,i/=10;
		c=i%10,i/=10;
		printf("%d,%d,%d\n\n",c,b,a);
		printf("Inverted=%d%d%d",a,b,c);
	}
	if(place==2)
	{
		int a,b;
		a=i%10,i/=10;
		b=i%10,i/=10;
		printf("%d,%d\n\n",b,a);
		printf("Inverted=%d%d",a,b);
	}
	if(place==1)
	{
		int a;
		a=i%10,i/=10;
		printf("%d\n\n",a);
		printf("Inverted=%d",a);
	}
	return 0;
} 
