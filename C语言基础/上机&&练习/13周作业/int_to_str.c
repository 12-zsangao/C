#include<stdio.h>
#include<math.h>
void int_to_str(int n)
{
	if(n>10)
		printf("%d",n);
	else
	{
		int digit=n/(int)pow(10,(int)log10(n));
		printf("%d",digit);
		int_to_str(n%(int)pow(10,(int)log10(n)));
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int_to_str(n);
	return 0;
}
