/*���ļ�1���ַ������ӡ���ļ�2*/
#include<stdio.h>
#include<stdlib.h>
int main()
{ 
	FILE *p,*q;
	char ch,filename1[20],filename2[20];
	gets(filename1);
	gets(filename2);
	if((p = fopen(filename1,"r")) == NULL||(q = fopen(filename2,"w")) == NULL)
	{
		perror("cannot open the file\n");
		exit(0);	//��ֹ����  
	}
	//ch = getchar();	�н�scanf���Ļس�
	ch = fgetc(p);	
	//ch = getchar(); ������������ַ���ӡ���ļ��� 
	while(ch != '*')
	{
		fputc(ch,q); 	//��ch��д���ļ�2�� 
		putchar(ch);	//��ch��ӡ����Ļ�� 
		ch = fgetc(p);	//ʹѭ���������� 
	 } 
	return 0;
 } 
