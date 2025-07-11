/*1. 两两相乘再相加
【问题描述】给定n个整数，求他们两两相乘再相加的和。
【输入形式】

第一行 表示整数个数

第二个 输入若干个整数

【输出形式】

两两相乘再相加的和*/
#include <stdio.h>
int main() {
    int  n;
    int i,j; 
    scanf("%d", &n);
    long arr[n];
    for ( i = 0; i < n; i++) {
        scanf("%ld", &arr[i]); 
    }

   long long sum = 0;
    for (i = 0; i < n - 1; i++) {
        for ( j = i + 1; j < n; j++) {
            sum += (long long)arr[i] * arr[j]; // 两两相乘并累加
        }
    }

    printf("%lld\n", sum);  // 输出结果
    return 0;
}
