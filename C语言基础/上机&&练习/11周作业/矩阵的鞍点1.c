#include <stdio.h>

int main() 
{
    int a[4][5];  // ����һ�� 4 �� 5 �еĶ�ά����
    int i, j, k, row, col, flag;

    // �����ά�����Ԫ��
    //printf("������ 4 �� 5 �еĶ�ά���飺\n");
    for (i = 0; i < 4; i++) 
	{
        for (j = 0; j < 5; j++) 
		{
            scanf("%d", &a[i][j]);
        }
    }

    row = 0;
    flag = 0;  // ����Ƿ��ҵ����㣬��ʼΪ 0��δ�ҵ���

    while (row < 4) 
	{  // �ӵ�һ�п�ʼ�������ж�
        int max = a[row][0];  // ���赱ǰ�еĵ�һ��Ԫ��Ϊ���ֵ
        col = 0;

        // �ҳ���ǰ�е����ֵ�������е�λ��
        for (j = 1; j < 5; j++) {
            if (a[row][j] > max) {
                max = a[row][j];
                col = j;
            }
        }

        int min = a[0][col];  // ���赱ǰ�еĵ�һ��Ԫ��Ϊ��Сֵ
        int min_row = 0;  // ��¼��Сֵ�����е�λ��

        // �ҳ���ǰ�е���Сֵ�������е�λ��
        for (i = 1; i < 4; i++) {
            if (a[i][col] < min) {
                min = a[i][col];
                min_row = i;
            }
        }

        // ������ֵ����λ�õ�Ԫ��ͬʱ���������е���Сֵ����Ϊ����
        if (min_row == row) 
		{
            printf("a[%d][%d]=%d", row , col ,a[row][col]);
            flag = 1;  // ����ҵ�����
            break;
        }
        row++;  // δ�ҵ����㣬������һ��
    }

    // ���δ�ҵ����㣬�����ʾ��Ϣ
    if (flag == 0) {
        printf("It is not exist.\n");
    }

    return 0;
}
