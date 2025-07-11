#include <stdio.h>

int main() {
    int n, x = 0, y = 0;
    scanf("%d", &n);
    int arr[n], a[n], b[n];

    // 分离非正数和正数
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] <= 0) {
            a[x++] = arr[i];
        } else {
            b[y++] = arr[i];
        }
    }

    // 寻找最小缺失正数
    for (int i = 1; i <= y + 1; i++) {  // 范围修正为 y+1，就算是内不缺也能输出n下一位 
        int found = 0;
        for (int j = 0; j < y; j++) {
            if (b[j] == i) {  // 检查正数数组b
                found = 1;			//嵌套循环O(n^2) 
                break;
            }
        }
        if (!found) {
            printf("%d", i); 
            return 0;	//找到最小正整数立即输出，以防继续进行输出其他正整数 ，包括未确实输出y 
        }
    }
    return 0;
}
