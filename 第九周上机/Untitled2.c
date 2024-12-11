#include<stdio.h>
int main()
{
	int i=0,j=0,k=0,l=0;
	char a;
	a=getchar();
	while(a!='\n')
	{
		if(a>='A'&&a<='Z'||a>='a'&&a<='z')
				i++;
			else if(a>='0'&&a<='9')
				j++;
				else if(a==' ')
				k++;
					else l++;
		a=getchar();
	}
	printf("i=%d,j=%d,k=%d,l=%d",i,j,k,l);
	return 0;
}
