/*int main()
{
	void XU(int **p,int n);
	int n;
	int i=0;
	scanf("%d",&n);
	int a[n];
	for(i;i<n;i++)
	scanf("%d",&a[n]);
	int *p=a;
	XU(&p,n);
	for(i;i<n;i++)
	printf("%d ",a[i]); 
	return 0;
}
void XU(int  **p,int n)
{
	int i=0,temp;
	for(i;i<n-1;i++)
	{
		if(*(*p+i)>*(*p+i+1))
		{
		temp=*(*p+i);
		*(*p+i)=*(*p+i+1);
		*(*p+i+1)=temp;
		}
	}
}*/
#include <stdio.h>

// ��������ʹ��ָ��ָ���ָ��ķ�����������������
void sort(int **p, int n) {
    int i, j;
    int *t;
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (*(*(p + j)) > *(*(p + j + 1))) {
                t = *(p + j + 1);
                *(p + j + 1) = *(p + j);
                *(p + j) = t;
            }
        }
    }
}

int main()
 {
    int n, i;
    scanf("%d", &n);
    int num[n];
    int *p[n]; // ����һ��ָ�����飬�����n��ָ��ָ���λ�ò�ȷ��

    // ��ʼ��ָ������
    for (i = 0; i < n; i++) {
        p[i] = &num[i]; // ����i�������ĵ�ַ����ָ�������p�ĵ�i��Ԫ��, ����ָ��ָ�򿪱ٵ��ڴ�
    }

    for (i = 0; i < n; i++) {
        scanf("%d", p[i]);
    }

    // ����������
    sort(p, n);

    for (i = 0; i < n; i++) {
        printf("%d ", *(*(p + i))); // ��������Ľ��
    }
    printf("\n");

    return 0;
}



