/*把文件1的字符逐个打印到文件2*/
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
		exit(0);	//终止程序  
	}
	//ch = getchar();	承接scanf语句的回车
	ch = fgetc(p);	
	//ch = getchar(); 将键盘输入的字符打印到文件上 
	while(ch != '*')
	{
		fputc(ch,q); 	//将ch读写到文件2上 
		putchar(ch);	//将ch打印到屏幕上 
		ch = fgetc(p);	//使循环继续进行 
	 } 
	return 0;
 } 
