//��һ�����У����е�һ������n,����ûһ��������ǰһ��������2�Ľ����������е��������� ��һ��5�� 
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

