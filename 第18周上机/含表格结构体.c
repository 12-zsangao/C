#include<stdio.h>
struct student 
{
	char name[20];
	long number;
	float score[3];
	float average;	
};

/*void input(struct student stu[],int n)
{ int i,j;
  for (i=0;i<n;i++)
  { 
  	 printf("\ninput name,number,English,mathema,physic\n"); /*��ӡ��ʾ��Ϣ*/
     /*gets(stu[i].name); /*��������*/
     /*scanf("%d",&stu[i].number); /*����ѧ��*/
     //for(j=0;j<3;j++)
     //scanf("%d",&stu[i].score[j]);/*�������Ƴɼ�*/    
  //}
//}
void input(struct student stu[],int n) /*����ṹ����������arr��n ��Ԫ��*/
{ int i,j;
  char temp[30];
  for (i=0;i<n;i++)
  { 
  	printf("\ninput name,number,English,mathema,physic\n"); /*��ӡ��ʾ��Ϣ*/
     gets(stu[i].name); /*��������*/
     gets(temp); /*����ѧ��*/
     stu[ i ].number = atol ( temp ) ;
    //�Ѳ���temp��ָ���ַ���ת��Ϊһ���������� long int �ͣ���
     for ( j = 0 ; j < 3 ; j++ )
     {   gets(temp); /*�������Ƴɼ�*/  
          stu[i].score[j] = atoi(temp) ;
    //�Ѳ���temp��ָ���ַ���ת��Ϊһ�������� int �ͣ���
     }
  }
}

float average(struct student stu[],int i)
{

	return (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
}

void aver(struct student stu[],int n)
{
	float a=0,b=0,c=0,d=0;
	float ave1,ave2,ave3,ave;
	int i;
	for(i=0;i<n;i++)
	{
		a+=stu[i].score[0];
		b+=stu[i].score[1];
		c+=stu[i].score[2];
		d+=average(stu,i);
	}
	ave1=a/n;
	ave2=b/n;
	ave3=c/n;
	ave=d/n;
	printf("|  		     | %7.2f | %7.2f | %7.2f | %7.2f |" , ave1 , ave2 , ave3 ,ave) ;
}

void sort(struct student stu[],int n)
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		if(average(stu,j)>average(stu,j+1))
		{
			temp = stu[j];
			stu[j] = stu[j+1];
			stu[j+1] = temp;
		}
	}
}

void output(struct student stu[],int n)
{
	int i,j;
    printf("*******************TABLE*******************\n"); /*��ӡ��ͷ*/
    printf("----------------------------------------------------\n"); /*���һ��ˮƽ��*/
    printf( "|%10s |%8s |%7s |%7s |%7s |%7s |\n" , "Name" , "Number" , " English " , " Mathema" ," physics " , " average " ) ;
	printf("----------------------------------------------------\n");
	for (i=0;i<n;i++)
  	{  printf( " |%10s|%8d| " ,stu[i].name,stu[i].number ); /*���������ѧ��*/
   	   for ( j = 0 ; j < 3 ; j++ )
       	   printf( " %7.2f | " , stu[i].score[j]) ; /*������Ƴɼ�*/
       	printf( " %7.2f | " ,(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0);		//���ƽ���ɼ� 
     	printf( "\n" ) ;
    	printf( "----------------------------------------------------\n " ) ;
  	}
}

int main()
{
	struct student stu[4];
	int n=4;
	input(stu,n);
	average(stu,n);
	sort(stu,n);
	output(stu,n);
	aver(stu,n);
	return 0;
}

