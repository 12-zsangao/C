#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
//老师想让这题体现指针相对于数组名的 ，建议用指针； 
// 交换两个字符串的函数
void swap(char *a, char *b) {
    char temp[100];
   
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// 对字符串数组进行排序的函数
void sortStrings(char *strs[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // 使用strcmp函数比较两个字符串的大小
            if (strcmp(strs[j], strs[j + 1])>0) {
                swap(strs[j], strs[j + 1]);
            }
        }
    }
}

int main() {
    char strs[6][100];
    //考虑把二维字符数组改为指针数组来做，这样能够节省内存 
    char *pstrs[6];
    int i;
    // 输入6个字符串
    for (i = 0; i < 6; i++) {
        scanf("%s", strs[i]);
        pstrs[i]=strs[i];
    }
    // 调用排序函数
    sortStrings(pstrs, 6);
    printf("These words are sorted as:\n");
    // 输出排序后的字符串
    for (i = 0; i < 6; i++) {
        printf("%s\n", pstrs[i]);
    }
    return 0;
}
