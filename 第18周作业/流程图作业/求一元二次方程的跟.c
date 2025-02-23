#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    // 计算一元二次方程的根
    double a, b, c;
    printf("请输入一元二次方程的系数 a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("方程有两个实根: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("方程有一个实根: x = %.2lf\n", x);
    } else {
        printf("复数根\n");
        return 0; 
    }
}
