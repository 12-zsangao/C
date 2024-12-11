int tian(int x,int y,int z)
{
	int a;
	if(y==1)a=0;
	if(y==2)a=31;
	if(y==3)a=31+28;
	if(y==4)a=31+28+31;
	if(y==5)a=31+28+31+30;
	if(y==6)a=31+28+31+30+31;
	if(y==7)a=31+28+31+30+31+30;
	if(y==8)a=31+28+31+30+31+30+31;
	if(y==9)a=31+28+31+30+31+30+31+31;
	if(y==10)a=31+28+31+30+31+30+31+31+30;
	if(y==11)a=31+28+31+30+31+30+31+31+30+31;
	if(y==12)a=31+28+31+30+31+30+31+31+30+31+30;
	a=a+z;
	return(a);
}
int nian(int q,int w,int t)
{
	int b,c;
	b=q;
	if((b%4==0&&b%100!=0)||b%400==0)c=1;
	else c=0;
	return(c);
}
#include<stdio.h>
int main()
{
	int d,e,f,u,i,o;
	scanf("%d,%d,%d",&d,&e,&f);
	u=tian(d,e,f);
	i=nian(d,e,f);
	o=u+i;
	printf("%d",o);
	return 0;
}
