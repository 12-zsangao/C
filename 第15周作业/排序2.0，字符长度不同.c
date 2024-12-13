#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
//��ʦ������������ָ��������������� ��������ָ�룻 
// ���������ַ����ĺ���
void swap(char *a, char *b) {
    char temp[100];
   
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// ���ַ��������������ĺ���
void sortStrings(char *strs[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // ʹ��strcmp�����Ƚ������ַ����Ĵ�С
            if (strcmp(strs[j], strs[j + 1])>0) {
                swap(strs[j], strs[j + 1]);
            }
        }
    }
}

int main() {
    char strs[6][100];
    //���ǰѶ�ά�ַ������Ϊָ�����������������ܹ���ʡ�ڴ� 
    char *pstrs[6];
    int i;
    // ����6���ַ���
    for (i = 0; i < 6; i++) {
        scanf("%s", strs[i]);
        pstrs[i]=strs[i];
    }
    // ����������
    sortStrings(pstrs, 6);
    printf("These words are sorted as:\n");
    // ����������ַ���
    for (i = 0; i < 6; i++) {
        printf("%s\n", pstrs[i]);
    }
    return 0;
}
