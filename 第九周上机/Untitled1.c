#include<stdio.h>
int main()
{
	int F1=1,F2=1;
	int i;
	int F[20]={1,1};
	for(i=2;i<20;i++)
		F[i]=F[i-1]+F[i-2];
	for(i=0;i<20;i++)
		{
		if(i%4==0) printf("\n");
		printf("%10d",F[i]);
		}
	return 0;
}
