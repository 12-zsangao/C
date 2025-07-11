#include<stdio.h>
int main()
	{
		float x,y,a;
		printf("\033[31m\033[5m\033[1m");
		for(y=1.3f;y>-1.1f;y-=0.1f)
		{
			for(x=-1.3f;x<1.3f;x+=0.048f)
			{
				a=x*x+y*y-1;
				if(a*a*a-x*x*y*y*y<0)
					printf("*");
				else printf(" ");
			}		
		puts("");
	 	}
	 	printf("\033[0m");
	 	printf("Àî»ÛÏèÇ°³ÌËÆ½õ");
	return 0;
	}
