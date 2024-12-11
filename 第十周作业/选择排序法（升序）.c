//选择排序（升序）
int main()
{
	int a[10]={0,15,8,4,13,6,10,17,19,1};
	int i, j,flag= 0,exchange = 0;
 
	/*	printf("排列前的数组为：");
		for (i = 0; i < 10; i++)
		{
			printf("%3d", a[i]);
		}
		printf("\\n");	*/
	for (i = 0; i < 10; i++)
	{
		flag = i;   //记录下标
		for (j = i + 1; j < 10; j++)
		{
			if (a[flag] >= a[j])  //flag和j下标比较，让flag指向最小的数
			{
				flag = j;
			}
		}
		if (flag != i)  //下标不同时(开始交换)
		{
			exchange = a[flag];
			a[flag] = a[i];
			a[i] = exchange;
		}
	}
 
	//printf("排列后的数组为：");
 
	for (i = 0; i < 10; i++)
	{
		printf(" %d", a[i]);
	}
	//printf("\\n");
	//system("pause");
	return 0;
}
