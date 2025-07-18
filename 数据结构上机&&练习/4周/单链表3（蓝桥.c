#include <stdio.h>
#include <stdlib.h>

// 最小值索引函数 
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

// 鎵ц涓�娆℃搷浣�
void performOperation(int *arr, int *n, int *k) {
	int i;
    int minIndex = findMinIndex(arr, *n);
    int minValue = arr[minIndex];

    // 澶勭悊宸﹁竟鐩搁偦鍏冪礌
    if (minIndex > 0) {
        arr[minIndex - 1] += minValue;
    }

    // 澶勭悊鍙宠竟鐩搁偦鍏冪礌
    if (minIndex < *n - 1) {
        arr[minIndex + 1] += minValue;
    }

    // 鍒犻櫎鏈�灏忓��
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
