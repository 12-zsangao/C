#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    // ����һԪ���η��̵ĸ�
    double a, b, c;
    printf("������һԪ���η��̵�ϵ�� a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("����������ʵ��: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("������һ��ʵ��: x = %.2lf\n", x);
    } else {
        printf("������\n");
        return 0; 
    }
}
