#include<stdio.h>
int main()
{
	void invert(int *p,int n);
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	invert(a,n); 
	return 0;
}
void invert(int *p,int n)
{
	int i,temp;
	 for(i=0;i<n;i++)
	 printf("%d ",*(p+n-i-1));
	 //����ֱ�ӵ������������Ҳ���ԶԳ���λ������
	 //�����ַ�ʽ���β�ʵ����ָ�����������
	 //������ֱ����ʵ�����������β�ָ�롣 
}

