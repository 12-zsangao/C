/*��һ�������ļ�����Ϣ���Ƶ���һ�������ļ��У�
���罫in.txt�е����ݶ��������Ƶ�out.txt�У�
ͬʱ��ʾ����Ļ�ϡ�
����in.txt�ļ��е�������2���ַ���*/
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
