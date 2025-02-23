#include<stdio.h>
#include<string.h>
void input(char a[][20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		gets(a[i]);
	}
}

void sort(char a[][20],int n)
{
	int i,j;
	char temp[20];
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			 {
			 strcpy(temp,a[j+1]);
			 strcpy(a[j+1],a[j]); 
			 strcpy(a[j],temp);
			}
		}
	}
}
void output(char a[][20],int n)
{
	int i;
	for(i=0;i<n;i++)
	//printf("%s\n",a[i]);
	puts(a[i]);
}

int main()
{
	char a[5][20];
	input(a,5);
	sort(a,5);
	output(a,5);
	return 0;
}
