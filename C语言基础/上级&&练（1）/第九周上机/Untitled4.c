#include<stdio.h>
#include<math.h>
int main()
{
	int i,k,j,n;
	for(i=101;i<200;i+=2)
		{
			k=sqrt(i);
			for(j=2;j<=k;j++)
				{
				if(i%j==0) break;}
		if(j>k) printf("%d is a prime number\n\n",i);
		}
	return 0;
}
