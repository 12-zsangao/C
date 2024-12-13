#include <iostream>
using namespace std;
const float PI = 3.14;
// 计算圆面积的函数
float circleArea(float r) {
    return PI * r * r;
}
int main() {
    float diameter, height;
    cin >> diameter >> height;
    if (diameter <= 0) {
        cout << "The input value must greater than 0!" << endl;
    } else {
        float radius = diameter / 2;
        float volume = circleArea(radius) * height;
        cout << "The volumn of cylinder is " << volume << endl;
    }
    return 0;
}
