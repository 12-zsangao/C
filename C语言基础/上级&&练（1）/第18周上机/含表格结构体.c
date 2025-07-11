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
  	 printf("\ninput name,number,English,mathema,physic\n"); /*打印提示信息*/
     /*gets(stu[i].name); /*输入姓名*/
     /*scanf("%d",&stu[i].number); /*输入学号*/
     //for(j=0;j<3;j++)
     //scanf("%d",&stu[i].score[j]);/*输入三科成绩*/    
  //}
//}
void input(struct student stu[],int n) /*输入结构体类型数组arr的n 个元素*/
{ int i,j;
  char temp[30];
  for (i=0;i<n;i++)
  { 
  	printf("\ninput name,number,English,mathema,physic\n"); /*打印提示信息*/
     gets(stu[i].name); /*输入姓名*/
     gets(temp); /*输入学号*/
     stu[ i ].number = atol ( temp ) ;
    //把参数temp所指的字符串转换为一个长整数（ long int 型）。
     for ( j = 0 ; j < 3 ; j++ )
     {   gets(temp); /*输入三科成绩*/  
          stu[i].score[j] = atoi(temp) ;
    //把参数temp所指的字符串转换为一个整数（ int 型）。
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
    printf("*******************TABLE*******************\n"); /*打印表头*/
    printf("----------------------------------------------------\n"); /*输出一条水平线*/
    printf( "|%10s |%8s |%7s |%7s |%7s |%7s |\n" , "Name" , "Number" , " English " , " Mathema" ," physics " , " average " ) ;
	printf("----------------------------------------------------\n");
	for (i=0;i<n;i++)
  	{  printf( " |%10s|%8d| " ,stu[i].name,stu[i].number ); /*输出姓名、学号*/
   	   for ( j = 0 ; j < 3 ; j++ )
       	   printf( " %7.2f | " , stu[i].score[j]) ; /*输出三科成绩*/
       	printf( " %7.2f | " ,(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0);		//输出平均成绩 
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

