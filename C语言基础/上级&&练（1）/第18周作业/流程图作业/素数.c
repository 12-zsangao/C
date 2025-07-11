#include <stdio.h>

int main() {
    int i, j;
    int isPrime;

    printf("100以内的素数有：\n");
    for (i = 2; i < 100; i++) { // 循环检查从2到99的每个数字
        isPrime = 1; // 假设i是素数
        for (j = 2; j * j <= i; j++) { // 检查i是否能被2到sqrt(i)之间的数整除
            if (i % j == 0) {
                isPrime = 0; // 如果能整除，则i不是素数
                break;
            }
        }
        if (isPrime) {
            printf("%d ", i); // 如果是素数，输出该数
        }
    }
    printf("\n");
    return 0;
}


