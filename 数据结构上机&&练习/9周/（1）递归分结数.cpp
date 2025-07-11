#include <iostream>
#include <math.h>
using namespace std;

void set(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int first = 1;
    int i;
    for (i = 16; i >= 0; i--) {
        int power = pow(2, i);
        if (power <= n) {
            if (!first) {
                printf("+");
            }
            first = 0;
            printf("2");
            if (i > 1) {
                printf("{");
                set(i);
                printf("}");
            } else if (i == 1) {
                // Do nothing, already printed "2"
            } else if (i == 0) {
                printf("{0}");
            }
            n =n - power;
        }
    }
}

int main() {
    int n;
    cin>>n;
    set(n);
    return 0;
}
