#include <stdio.h>

// 查找两个升序序列的中位数
int search(int A[], int B[], int n) {
    int leftA = 0, rightA = n - 1;
    int leftB = 0, rightB = n - 1;

    while (rightA > leftA) {
        int midA = (leftA + rightA) / 2;
        int midB = (leftB + rightB) / 2;
        int len = rightA - leftA + 1;

        if (A[midA] == B[midB]) {
            return A[midA];
        } else if (A[midA] < B[midB]) {
            if (len % 2 == 0) {
                leftA = midA + 1;
                rightB = midB;
            } else {
                leftA = midA;
                rightB = midB;
            }
        } else {
            if (len % 2 == 0) {
                leftB = midB + 1;
                rightA = midA;
            } else {
                leftB = midB;
                rightA = midA;
            }
        }
    }

    return (A[leftA] < B[leftB]) ? A[leftA] : B[leftB];
}

int main() {
    int A[100], B[100];
    int i = 0, j = 0;
    int num;

    // 输入序列 A
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        A[i++] = num;
    }

    // 输入序列 B
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        B[j++] = num;
    }

    int med = search(A, B, i);
    printf("mid=%d\n", med);

    return 0;
}    
