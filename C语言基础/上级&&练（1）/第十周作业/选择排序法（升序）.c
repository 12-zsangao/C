//ѡ����������
int main()
{
	int a[10]={0,15,8,4,13,6,10,17,19,1};
	int i, j,flag= 0,exchange = 0;
 
	/*	printf("����ǰ������Ϊ��");
		for (i = 0; i < 10; i++)
		{
			printf("%3d", a[i]);
		}
		printf("\\n");	*/
	for (i = 0; i < 10; i++)
	{
		flag = i;   //��¼�±�
		for (j = i + 1; j < 10; j++)
		{
			if (a[flag] >= a[j])  //flag��j�±�Ƚϣ���flagָ����С����
			{
				flag = j;
			}
		}
		if (flag != i)  //�±겻ͬʱ(��ʼ����)
		{
			exchange = a[flag];
			a[flag] = a[i];
			a[i] = exchange;
		}
	}
 
	//printf("���к������Ϊ��");
 
	for (i = 0; i < 10; i++)
	{
		printf(" %d", a[i]);
	}
	//printf("\\n");
	//system("pause");
	return 0;
}
