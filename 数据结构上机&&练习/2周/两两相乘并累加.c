/*1. ������������
����������������n�������������������������ӵĺ͡�
��������ʽ��

��һ�� ��ʾ��������

�ڶ��� �������ɸ�����

�������ʽ��

�����������ӵĺ�*/
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
            sum += (long long)arr[i] * arr[j]; // ������˲��ۼ�
        }
    }

    printf("%lld\n", sum);  // ������
    return 0;
}
