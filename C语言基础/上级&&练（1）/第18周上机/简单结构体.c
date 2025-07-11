#include<stdio.h>
struct stu
{
	int number;
	char name[20];
	float score[4];
 };
 
 void input(struct stu a[])
 {
 	int i,j;
 	char temp[20];
 	for(i=0;i<3;i++)
 	{
 		gets(temp); /*输入学号*/
        a[ i ].number = atol ( temp ) ;
 		gets(a[i].name );
 	 for ( j = 0 ; j < 3 ; j++ )
     {   
	 gets(temp); /*输入三科成绩*/  
     a[i].score[j] = atoi(temp) ;
	 }
	 }
 }
 
 void ave(struct stu a[])
 {
 	int i;
 	for(i=0;i<3;i++)
		a[i].score[3] = (a[i].score[0]+a[i].score[1]+a[i].score[2])/3.0;
 }
 

 void cal(struct stu a[])
 {
 	float temp;
 	int i; 
 	/*float max=a[0].score[3];				计算平均成绩最大 
 	for(i=1;i<3;i++)					
 	{	
 		if(a[i].score[3]>max)
		 {						
		 	temp = a[i].score[3];
		 	a[i].score[3] = max;
		 	max = a[i].score[3];
		  } 
	 }*/
	 temp = a[0].score[3]+a[1].score[3]+a[2].score[3];
	 printf("The average score of these students is:  %.2f\n",temp/3.0);
	 float x = 0,y = 0,z = 0;
	 for(i=0;i<3;i++)
	 {
	 	x += a[0].score[i];
	 	y += a[1].score[i];
	 	z += a[2].score[i];
	 }
	 float sum_max;
	 sum_max = (x>y?x:y)>z?(x>y?x:y):z;
	/*switch(sum_max)
	{
		case x :printf("The highest total score is: %.2f. No.1, zhang\n",x);break;
		case y :printf("The highest total score is: %.2f. No.1, li\n",y);break;
		case z :printf("The highest total score is: %.2f. No.1, wang\n",z);break;
		default :printf("请重新输入数据！");			case标签后接常量表达式 
	}*/
	if(sum_max==x) 
		printf("The highest total score is: %.2f. No.1, zhang\n",x);
	if(sum_max==y)
		printf("The highest total score is: %.2f. No.1, li\n",y);
	if(sum_max==y)
		printf("The highest total score is: %.2f. No.1, wang\n",z);
}
 
 void output(struct stu a[])
 {
 	printf("No. name  score1 score2 score3\n");
 	int i,j;
 	for(i=0;i<3;i++)
 		{
 			printf("%d  %s  ",a[i].number,a[i].name);
 			for(j=0;j<3;j++)
			 printf("%.2f ",a[i].score[j]);
			 printf("\n");
	 	}
	 	printf("\n");
 }

 int main()
 {
 	struct stu a[3];
 	input(a);
 	ave(a);
 	output(a);
 	cal(a);
 	return 0;
} 
