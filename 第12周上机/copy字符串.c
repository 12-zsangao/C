#include<stdio.h>
int main()
{
	char s1[20],s2[20];
	gets(s2);
	int i;
	for(i=0;i<20;i++)
		s1[i]=s2[i];
	printf("s1:\n");
	puts(s1); 
	return 0;
}
