//有一个序列，序列第一个数是n,后面没一个数字事前一个数整除2的结果，输出序列的所有正项 ，一行5个 
#include<stdio.h>
int main()
{
	long long n;
	int i;
	scanf("%lld",&n);
	while(n>0)
	{
		 for(i=0;i<5;i++)
	 	{
	 		if(n==0)  break;
 			printf("%lld ",n);
 			n=n>>1;
 	 	} 
 	 	printf("\n");
		/*printf("%lld ",n);
		n=n>>1;*/
	}
	return 0;
 } 

