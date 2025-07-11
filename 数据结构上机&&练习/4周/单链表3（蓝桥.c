#include <stdio.h>
#include <stdlib.h>

// ��Сֵ�������� 
int findMinIndex(int *arr, int n) {
	int i;
    int minIndex = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// 执行一次操作
void performOperation(int *arr, int *n, int *k) {
	int i;
    int minIndex = findMinIndex(arr, *n);
    int minValue = arr[minIndex];

    // 处理左边相邻元素
    if (minIndex > 0) {
        arr[minIndex - 1] += minValue;
    }

    // 处理右边相邻元素
    if (minIndex < *n - 1) {
        arr[minIndex + 1] += minValue;
    }

    // 删除最小值
    for (i = minIndex; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    (*k)--;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
	int i;
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (k > 0) {
        performOperation(arr, &n, &k);
    }

    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }

    free(arr);
    return 0;
}
