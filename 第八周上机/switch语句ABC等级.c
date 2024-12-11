#include<stdio.h>
int main()
{
	float a;
	scanf("%f",&a);
	int b=a/10;
	switch(b)
	{
		case 10:
		case 9: printf("score=%.1f,grade=A",a);break;
		case 8: printf("score=%.1f,grade=B",a);break;
		case 7: printf("score=%.1f,grade=C",a);break;
		case 6: printf("score=%.1f,grade=D",a);break;
		case 5: 
		case 4:
		case 3:
		case 2:
		case 1:
		case 0: printf("score=%.1f,grade=E",a);break;
		default:printf("score should between 0 and 100");
	}
	return 0;
}
