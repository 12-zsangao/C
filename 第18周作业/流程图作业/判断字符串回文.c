#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    // �ж��ַ����Ƿ�Ϊ����
    char str[100];
    int i;
    printf("������һ���ַ���: ");
    scanf("%s", str);

    int len = strlen(str);		//���ַ������� 
    int flag = 1;
    for ( i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("������ַ����ǻ��ġ�\n");
    } else {
        printf("������ַ������ǻ��ġ�\n");
    }

    return 0;
}
