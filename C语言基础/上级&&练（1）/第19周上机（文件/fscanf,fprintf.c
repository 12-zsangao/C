/*�����ļ�file1.txt�б���������ѧ���ṹ������ݣ��������£�

1 zhang 85 64.5 95

2 li 95 78 88.5

3 zhao 67.5 75 83

Ҫ�󣺶���һ���Ӻ������ú���fscanf���ļ�file1.txt��ѧ�����ݶ�����
�����浽һ��ѧ���ṹ�������С�
Ȼ����һ���Ӻ��������������ѧ����ƽ���֣�
������ƽ���ֵó���ѧ���ĵȼ�
��90������Ϊ'A',90������80����Ϊ'B',80������70����Ϊ'C',70������60����Ϊ'D'��60����Ϊ'E'����
�����һ���Ӻ������ú���fprintf����Щ������д���ļ�file2.txt�У�
д��ʱҪ��ɼ����ݰ��������λ��Ϊ6�Ҿ�ȷ��С�����2λ����ʽ�����
���������м䶼�ÿո�ֿ���
ͬʱ����������ļ���ͬ�ĸ�ʽҪ����Щ������ʾ����Ļ�ϡ�
���������
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
