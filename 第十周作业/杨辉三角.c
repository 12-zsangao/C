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
		//注意访问数组是从0开始（数组的最低下标是0）
 
		for (b = 0; b <=a; b++)
		{
			if(a==b)
			arr[a][b] = 1;
			if(a>1 && b>=1)
			arr[a][b] = arr[a - 1][b - 1] + arr[a - 1][b];//上一行前一列和本列数之和
			printf("%-5d ", arr[a][b]);//赋值完一行后直接打印得到的整体打印效果就是直接
		}
 
		printf("\n");
	}
 
	return 0;
}
