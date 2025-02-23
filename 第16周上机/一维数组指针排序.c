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

// 排序函数，使用指向指针的指针的方法对整数进行排序
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
    int *p[n]; // 声明一个指针数组，里面的n个指针指向的位置不确定

    // 初始化指针数组
    for (i = 0; i < n; i++) {
        p[i] = &num[i]; // 将第i个整数的地址赋给指针数组的p的第i个元素, 现在指针指向开辟的内存
    }

    for (i = 0; i < n; i++) {
        scanf("%d", p[i]);
    }

    // 调用排序函数
    sort(p, n);

    for (i = 0; i < n; i++) {
        printf("%d ", *(*(p + i))); // 输出排序后的结果
    }
    printf("\n");

    return 0;
}



