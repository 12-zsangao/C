#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,m;
	scanf("%f,%f,%f",&a,&b,&c);
	if(fabs(a)>fabs(b)) m=a;
		else m=b;
	if(fabs(m)>fabs(c)) m=m;
		else m=c;
	printf("%.2f",m);
	return 0;
}
