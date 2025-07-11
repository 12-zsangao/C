#include<stdio.h>
struct student
{
	int num;
	float score;
}student[2]; 

int main()
{
	int i,a;
	for(i=0;i<2;i++)
	{
	scanf("%d",&a);
	scanf("%f",&student[i].score);
	}
	printf("num     score\n\n");
	float aver;
	aver = (student[0].score+student[1].score)/2.0;
	printf("01     %.2f\n",student[0].score);
	printf("02     %.2f\n",student[1].score);
	printf("average %.2f",aver);
	return 0;
}
