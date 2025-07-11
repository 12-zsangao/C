#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    // 判断字符串是否为回文
    char str[100];
    int i;
    printf("请输入一个字符串: ");
    scanf("%s", str);

    int len = strlen(str);		//求字符串长度 
    int flag = 1;
    for ( i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        printf("输入的字符串是回文。\n");
    } else {
        printf("输入的字符串不是回文。\n");
    }

    return 0;
}
