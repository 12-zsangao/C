/*【问题描述】在主函数中用函数fscanf
从磁盘的file.txt文件中读入一个字符串，
然后调用子函数来判断其是否为回文串
（左右对称的字符串，例如level，dad等），
最后根据判断结果在主函数中输出Yes或No。*/
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
