#include <stdio.h>

int main() {
    int i, j;
    int isPrime;

    printf("100���ڵ������У�\n");
    for (i = 2; i < 100; i++) { // ѭ������2��99��ÿ������
        isPrime = 1; // ����i������
        for (j = 2; j * j <= i; j++) { // ���i�Ƿ��ܱ�2��sqrt(i)֮���������
            if (i % j == 0) {
                isPrime = 0; // �������������i��������
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i); // ������������������
        }
    }
    printf("\n");
    return 0;
}


