#include <stdio.h>

void shellSort(int arr[], int n, int gaps[], int numGaps) {
    for (int k = 0; k < numGaps; k++) {
        int gap = gaps[k];
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }

        // ���ÿһ��������
        for (int i = 0; i < n; i++) {
            printf("%d", arr[i]);
            if (i != n - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int arr[9];
    int gaps[3];

    // ��������Ԫ��
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }

    // ��������
    for (int i = 0; i < 3; i++) {
        scanf("%d", &gaps[i]);
    }

    shellSort(arr, 9, gaps, 3);

    return 0;
}

