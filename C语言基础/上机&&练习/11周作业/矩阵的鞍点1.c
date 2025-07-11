#include <stdio.h>

int main() 
{
    int a[4][5];  // 定义一个 4 行 5 列的二维数组
    int i, j, k, row, col, flag;

    // 输入二维数组的元素
    //printf("请输入 4 行 5 列的二维数组：\n");
    for (i = 0; i < 4; i++) 
	{
        for (j = 0; j < 5; j++) 
		{
            scanf("%d", &a[i][j]);
        }
    }

    row = 0;
    flag = 0;  // 标记是否找到鞍点，初始为 0（未找到）

    while (row < 4) 
	{  // 从第一行开始，逐行判断
        int max = a[row][0];  // 假设当前行的第一个元素为最大值
        col = 0;

        // 找出当前行的最大值及所在列的位置
        for (j = 1; j < 5; j++) {
            if (a[row][j] > max) {
                max = a[row][j];
                col = j;
            }
        }

        int min = a[0][col];  // 假设当前列的第一个元素为最小值
        int min_row = 0;  // 记录最小值所在行的位置

        // 找出当前列的最小值及所在行的位置
        for (i = 1; i < 4; i++) {
            if (a[i][col] < min) {
                min = a[i][col];
                min_row = i;
            }
        }

        // 如果最大值所在位置的元素同时是其所在列的最小值，即为鞍点
        if (min_row == row) 
		{
            printf("a[%d][%d]=%d", row , col ,a[row][col]);
            flag = 1;  // 标记找到鞍点
            break;
        }
        row++;  // 未找到鞍点，继续下一行
    }

    // 如果未找到鞍点，输出提示信息
    if (flag == 0) {
        printf("It is not exist.\n");
    }

    return 0;
}
