/*将一个磁盘文件的信息复制到另一个磁盘文件中，
比如将in.txt中的内容读出并复制到out.txt中，
同时显示到屏幕上。
假设in.txt文件中的有如下2行字符：*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *a,*b;
	char str[20];
	a = fopen("in.txt","r");
	if(a == NULL){
	perror("connot open this file");
	exit(0);} 
	b = fopen("out.txt","w");
	if(b == NULL){
	perror("connot open this file");
	exit(0);}			
	while(fgets(str,sizeof(str),a) != NULL){
		fputs(str,b);
		printf("%s",str);}
	fclose(a);
	fclose(b);
	return 0;
}
