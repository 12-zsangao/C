/*假设文件file1.txt中保存了三个学生结构体的数据，内容如下：

1 zhang 85 64.5 95

2 li 95 78 88.5

3 zhao 67.5 75 83

要求：定义一个子函数，用函数fscanf从文件file1.txt将学生数据读出，
并保存到一个学生结构体数组中。
然后定义一个子函数，计算出三个学生的平均分，
并根据平均分得出该学生的等级
（90分以上为'A',90以下且80以上为'B',80以下且70以上为'C',70以下且60以上为'D'，60以下为'E'）。
最后定义一个子函数，用函数fprintf将这些数据再写入文件file2.txt中，
写入时要求成绩数据按照域宽（即位宽）为6且精确到小数点后2位的形式输出，
所有数据中间都用空格分开。
同时按照与输出文件相同的格式要求将这些数据显示在屏幕上。
样例输出：
1 zhang  85.00  64.50  95.00 B

2 li  95.00  78.00  88.50 B

3 zhao  67.50  75.00  83.00 C*/ 
#include<stdio.h>
#include<stdlib.h>
	typedef struct 
	{
		int number;
		char name[20];
		float score[3];
		char grade;
	}Student;

void duru(Student stu[])
{
	FILE *a;
	a = fopen("file1.txt","r");
	if(a == NULL)
	{
		perror("connot open this file");
		exit(0); 
	}
	int i,j;
	for(i=0;i<3;i++)
	{
		fscanf(a,"%d ",&stu[i].number);
		fscanf(a,"%s ",&stu[i].name);
		for(j=0;j<3;j++)
		fscanf(a,"%f \n",&stu[i].score[j]);
	}
	fclose(a);
}

void rank(Student stu[])
{
	float ave[3];
	int i,j,c; 
	for(i=0;i<3;i++)
	{
		ave[i] = (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
	}
	for(i=0;i<3;i++)
	{
		c = ave[i]/10;
		switch(c)
		{
			case 10:
			case 9:		stu[i].grade='A';break;
			case 8:		stu[i].grade='B';break;
			case 7:		stu[i].grade='C';break;
			case 6:		stu[i].grade='D';break;
			default:	stu[i].grade='E';
		}
	}
	for(i=0;i<3;i++)
	{
		printf("%d %s ",stu[i].number,stu[i].name);
		for(j=0;j<3;j++) 
		printf("%6.2f",stu[i].score[j]);
		printf(" %c\n",stu[i].grade);
	 } 
}
void duchu(Student stu[])
{
	FILE *b;
	b = fopen("file2.txt","w");
	if(b == NULL)
	{
		perror("connot open this file");
		exit(0); 
	}
	int i,j;
	for(i=0;i<3;i++)
	{
		fprintf(b,"%d %s",stu[i].number,stu[i].name);
		for(j=0;j<3;j++)
		fprintf(b,"%6.2f",stu[i].score[j]);
		fprintf(b,"%c\n",stu[i].grade);
	}
	fclose(b);
}

int main()
{
	Student stu[3];
	duru(stu);
	rank(stu);
	duchu(stu);
	return 0;
}
