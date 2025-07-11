#include<stdio.h>
#include<math.h>
int main()
{
	float x1=2,x2=-2,y1=2,y2=-2,x,y,d1,d2,d3,d4;
	int r=1; 
	scanf("%f,%f",&x,&y);
	d1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
	d2=sqrt((x-x1)*(x-x1)+(y-y2)*(y-y2));
	d3=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
	d4=sqrt((x-x2)*(x-x2)+(y-y1)*(y-y1));
	if(d1<=r||d2<=r||d3<=r||d4<=r)
		printf("10");
	else printf("0");
	return 0;
}
