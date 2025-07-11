 #include <stdio.h>
#include <math.h>

double sss(double a) {
    double x_n = a;
    double x_n1;
    while (1) {
        x_n1 = (x_n + a / x_n) / 2;
        if (fabs(x_n1 - x_n) < 0.00001)
            break;
        x_n = x_n1;
    }
    return x_n1;
}

int main() {
    double a;
    scanf("%lf", &a);
    double result = sss(a);
    printf("%.3lf\n", result);
    return 0;
}
