#include<stdio.h>
#include<math.h>
int main()
{	
	int s;
	float n,pi,t;
	t=1;pi=0;s=1;n=1.0;
	while(fabs(t)>1e-6)
		{	
			pi=pi+t;
			s=-s;
			n=n+2;
			t=s/n;
		}
	pi=4*pi;
	printf("pi = %.6f",pi);
	return 0;
}
