/*�����������������������ú���fscanf
�Ӵ��̵�file.txt�ļ��ж���һ���ַ�����
Ȼ������Ӻ������ж����Ƿ�Ϊ���Ĵ�
�����ҶԳƵ��ַ���������level��dad�ȣ���
�������жϽ���������������Yes��No��*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
void judge(char str[],int n)
{
	int flag;	
	int i;
	int len = strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i] == str[len-i-1])
		flag = 1;
		else flag = 0;
	}
	if(flag == 1)
		printf("Yes.");
	else printf("No."); 
}
int main()
{
	FILE *fp;
	char str[20];
	fp = fopen("file.txt","r");
	if(fp == NULL)
	{
		perror("connot open this file"); 
		return 1;
	}
	fscanf(fp,"%s",str);
	fclose(fp); 
	judge(str,20);
	return 0;
}
