/*【问题描述】

  改进的冒泡排序算法可以遵循以下思想：

先对数组从左到右进行冒泡排序（升序），则最大的元素去到最右端

再对数组从右到左进行冒泡排序（降序），则最小的元素去到最左端

以此类推，依次改变冒泡的方向，并不断缩小未排序元素的范围，直到最后一个元素结束

【输入形式】

    从键盘输入8个整数

【输出形式】

   输出每一趟的排序结果。*/
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
		for(i=l;i<r;i++)				//升序 
		{
			if(a[i]>a[i+1]) swap(&a[i],&a[i+1]);
		}
		r--;
		
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
		
		for(i=r;i>l;i--)				//降序 
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
