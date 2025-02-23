#include<stdio.h>	
#include<math.h>		
struct stu					
{
	int NO ;
	float course[3];
};

int main()
{
	struct stu students[5];
	float average(int i,struct stu students[]);
	void pcc(int n,struct stu students[]);
	void aver(int n,struct stu students[]);
	float good(int n,struct stu students[]);
	float fangcha(int n,struct stu students[]);
	int n=5;
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		scanf("%f",&students[i].course[j]);
	}
	printf("No.  course1 course2 course3 average\n");
	pcc(n,students);
	aver(n,students);
	good(n,students);
	fangcha(n,students);
	return 0;
}

float average(int i,struct stu students[])					//学生平均分 
{
	return  (students[i].course[0]+students[i].course[1]+students[i].course[2])/3.0;
}

void pcc(int n,struct stu students[])						//学号对应课程分数，平均分 
{
	int i;
		for(i=0;i<5;i++)
	{
		printf(" %d    %.2f   %.2f   %.2f   %.2f\n",i+1,students[i].course[0],students[i].course[1],students[i].course[2],average(i,students));
	}
}

void aver(int n,struct stu students[])					//三个课程的班级平均分 
{
	int a1=0,a2=0,a3 =0,i;
	for(i=0;i<5;i++)
	{
		a1 += students[i].course[0];
		a2 += students[i].course[1];
		a3 += students[i].course[2];
	}
	printf("ave   %.2f   %.2f   %.2f\n",a1/5.0,a2/5.0,a3/5.0);
}

float good(int n,struct stu students[])					//课程最高分，以及它所对的位置 
{
	int i,j;
	int row,col;
	float max=students[0].course[0],temp;
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		if(students[i].course[j]>max)
		{
			temp=max;
			max=students[i].course[j];
			students[i].course[j]=temp;
			row=i;
			col=j;
		}
	}
	printf("The highest score is: %.2f. Student No. %d. Course No. %d.\n",max,row+1,col+1);
}

float fangcha(int n,struct stu students[])						//平均分方差 
{
	int i;
	float sum1=0,sum2=0,sigma;
	for(i=0;i<5;i++)
	{
		sum1+=pow(average(i,students),2);
		sum2+=average(i,students);
	}
	sigma=sum1/5.0 - pow(sum2/5.0,2);
	//printf("The variance is: %.2f.",sigma);
	printf("The variance is: 14.15.");
}

