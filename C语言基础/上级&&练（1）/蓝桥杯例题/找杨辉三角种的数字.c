#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j,k;
    long long target;
    scanf("%lld", &target);
    long long *prevRow = (long long *)malloc(10000 * sizeof(long long));
    long long *currRow = (long long *)malloc(10000 * sizeof(long long));
    int num = 1;

    prevRow[1] = 1;
    if (target == 1) {
        printf("%d\n", num);
        free(prevRow);
        free(currRow);
        return 0;
    }

    for ( i = 2; ; i++) {
        currRow[1] = 1;
        for ( j = 2; j <= i; j++) {
            currRow[j] = prevRow[j - 1] + prevRow[j];
            num++;
            if (currRow[j] == target) {
                printf("%d\n", num);
                free(prevRow);
                free(currRow);
                return 0;
            }
            if (currRow[j] > target) break; 
        }
        if (currRow[i - 1] > target) break; 
        for ( k = 1; k <= i; k++) {
            prevRow[k] = currRow[k]; 
        }
    }

    printf("Ã»ÕÒµ½\n"); 
    free(prevRow);
    free(currRow);
    return 0;
}

