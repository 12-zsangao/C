/*������������

  �Ľ���ð�������㷨������ѭ����˼�룺

�ȶ���������ҽ���ð���������򣩣�������Ԫ��ȥ�����Ҷ�

�ٶ�������ҵ������ð�����򣨽��򣩣�����С��Ԫ��ȥ�������

�Դ����ƣ����θı�ð�ݵķ��򣬲�������Сδ����Ԫ�صķ�Χ��ֱ�����һ��Ԫ�ؽ���

��������ʽ��

    �Ӽ�������8������

�������ʽ��

   ���ÿһ�˵���������*/
#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void Bubble_Sort_pro(int a[],int n)
{
	int i,l=0,r=n-1;
	while(l<r)
	{
		for(i=l;i<r;i++)				//���� 
		{
			if(a[i]>a[i+1]) swap(&a[i],&a[i+1]);
		}
		r--;
		
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
		
		for(i=r;i>l;i--)				//���� 
		{
			if(a[i]<a[i-1]) swap(&a[i],&a[i-1]);
		}
		l++;
		
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
}
int main()
{
	int n=8;
	int a[n],i;
	for(i=0;i<n;i++)  scanf("%d",&a[i]);
	Bubble_Sort_pro(a,n);
	return 0;
}
