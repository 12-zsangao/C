#include<stdio.h> 
int main()
{
	int arr[10][10] = { 0 };
	int a = 1;
	int b = 1;
 
	for (a = 0;  a < 10; a++)
	{
		/*b = 10 - a;
	    while (b--)
		{
			printf("  ");
		}*/
 
		arr[a][0] = 1;
		//ע����������Ǵ�0��ʼ�����������±���0��
 
		for (b = 0; b <=a; b++)
		{
			if(a==b)
			arr[a][b] = 1;
			if(a>1 && b>=1)
			arr[a][b] = arr[a - 1][b - 1] + arr[a - 1][b];//��һ��ǰһ�кͱ�����֮��
			printf("%-5d ", arr[a][b]);//��ֵ��һ�к�ֱ�Ӵ�ӡ�õ��������ӡЧ������ֱ��
		}
 
		printf("\n");
	}
 
	return 0;
}
