#include<stdio.h>
#include<string.h>
int main()
{
	void well(float a[][6],int n);
	void worse(float a[][6],int n);
	int i,j,n=4;
	char c[5][100];
		for(i=0;i<5;i++)
		{
			gets(c[i]);
		}
	float arr[4][6];
	for(i=0;i<4;i++)
	{
		for(j=0;j<6;j++)
		scanf("%f",&arr[i][j]); 
	}
	float sum=arr[0][1]+arr[1][1]+arr[2][1]+arr[3][1];
	float average=sum/4.0;
	printf("course 1:English average score:    %.2f\n",average);
	printf("Student who is fail in two courses:\n");
	worse(arr,n);
	printf("Students whose score is good:\n");
	well(arr,n);
	return 0;
}
void worse(float a[][6],int n)
{	
	int i,j,num=0;
	float m=0;
		for(i=0;i<n;i++)
	{
		num=0;
		for(j=1;j<6;j++)
		if(a[i][j]<60.0)
			num++;
			if(num>=2)
			{
				printf("NO.     English   Computer       Math    Physics  Chemistry    average");
				printf("/n");
				printf("%f   ",a[i][0]);
				for(j=1;j<6;i++)
				printf("%.2f   ",a[i][j]);
				m=(a[i][1]+a[i][2]+a[i][3]+a[i][4]+a[i][5])/5;
				printf("   %.2f",m); 
			 } break;
	}
}
void well(float a[][6],int n)
{
	int i,j,b;
	float sum1;
		for(i=0;i<n;i++)
	{
		sum1=0;
		for(j=1;j<6;j++)
		sum1=sum1+a[i][j];
		if(sum1>450.0||(a[i][1]>85&&a[i][2]>85&&a[i][3]>85&&a[i][4]>85&&a[i][5]>85))
		{
			printf("NO.     English   Computer       Math    Physics  Chemistry    average");
			printf("\n");
			printf("%d    ",(int)a[i][0]);
			for(j=1;j<6;j++)
			printf("%.2f   ",a[i][j]);
			printf("%.2f",sum1/5.0);
		}
	}
}

