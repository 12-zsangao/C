#include <stdio.h>

int main() {
    int n, x = 0, y = 0;
    scanf("%d", &n);
    int arr[n], a[n], b[n];

    // ���������������
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] <= 0) {
            a[x++] = arr[i];
        } else {
            b[y++] = arr[i];
        }
    }

    // Ѱ����Сȱʧ����
    for (int i = 1; i <= y + 1; i++) {  // ��Χ����Ϊ y+1���������ڲ�ȱҲ�����n��һλ 
        int found = 0;
        for (int j = 0; j < y; j++) {
            if (b[j] == i) {  // �����������b
                found = 1;			//Ƕ��ѭ��O(n^2) 
                break;
            }
        }
        if (!found) {
            printf("%d", i); 
            return 0;	//�ҵ���С����������������Է���������������������� ������δȷʵ���y 
        }
    }
    return 0;
}
