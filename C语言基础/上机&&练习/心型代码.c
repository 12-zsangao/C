#include<stdio.h>
int main()
	{
		float x,y,a;
		
		for(y=1.3f;y>-1.1f;y-=0.1f)
		{
			for(x=-1.3f;x<1.3f;x+=0.05f)
			{
				a=x*x+y*y-1;
				if(a*a*a-x*x*y*y*y<0)
					printf("*");
				else printf(" ");
			}		
		puts("");
	 	}
	return 0;
	}
