#include<stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
int main()
{
	int sss(struct date one);
	struct date one;
	scanf("%d,%d,%d",&one.year,&one.month,&one.day);
	printf("It is the %dth day in %d",sss(one),one.year) ;
	return 0;
 } 
int sss(struct date one) 
 {
 	int sum;
 	if(one.year % 4 ==0&&one.year % 100 !=0||one.year % 400 ==0)
 	{
 		if(one.month==1)
 		sum=one.day;
 		if(one.month==2)
 		sum=one.day+31;
 		if(one.month==3)
 		sum=one.day+31+29;
		 if(one.month==4)
 		sum=one.day+31+31+29;
		 if(one.month==5)
 		sum=one.day+31+31+29+30;
		 if(one.month==6)
 		sum=one.day+31+31+29+30+31;
		 if(one.month==7)
 		sum=one.day+31+31+29+30+31+30;
		 if(one.month==8)
 		sum=one.day+31+31+29+30+31+30+31;
		 if(one.month==9)
 		sum=one.day+31+31+29+30+31+30+31+31;
 		if(one.month==10)
 		sum=one.day+31+31+29+30+31+30+31+31+30;
 		if(one.month==11)
 		sum=one.day+31+31+31+29+30+31+30+31+31+30;
 		if(one.month==12)
 		sum=one.day+30+31+31+31+29+30+31+30+31+31+30;
	 }
	 else
	 {
	 	if(one.month==1)
 		sum=one.day;
 		if(one.month==2)
 		sum=one.day+31;
 		if(one.month==3)
 		sum=one.day+31+28;
		 if(one.month==4)
 		sum=one.day+31+31+28;
		 if(one.month==5)
 		sum=one.day+31+31+28+30;
		 if(one.month==6)
 		sum=one.day+31+31+28+30+31;
		 if(one.month==7)
 		sum=one.day+31+31+28+30+31+30;
		 if(one.month==8)
 		sum=one.day+31+31+28+30+31+30+31;
		 if(one.month==9)
 		sum=one.day+31+31+28+30+31+30+31+31;
 		if(one.month==10)
 		sum=one.day+31+31+28+30+31+30+31+31+30;
 		if(one.month==11)
 		sum=one.day+31+31+31+28+30+31+30+31+31+30;
 		if(one.month==12)
 		sum=one.day+30+31+31+31+28+30+31+30+31+31+30;
	 }
	 return sum;
 }
