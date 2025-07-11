#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

void printChristmasTree(int height) {
    srand(time(0)); // 初始化随机数种子
    for (int i = 1; i <= height; ++i) {
        for (int j = i; j < height; ++j) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); ++k) {
            // 随机生成装饰
            int randomNum = rand() % 10;
            if (randomNum < 2) {
                cout << "\033[1;31mo\033[0m"; // 红色装饰球
            } else if (randomNum < 4) {
                cout << "\033[1;33m+\033[0m"; // 黄色星星
            } else if (randomNum < 6) {
                cout << "\033[1;34m@\033[0m"; // 蓝色铃铛
            } else if (randomNum < 8) {
                cout << "\033[1;32m$\033[0m"; // 绿色礼物
            } else {
                cout << "\033[1;37m*\033[0m"; // 白色树叶
            }
        }
        cout << endl;
    }
}

void animateChristmasTree(int height, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        system("clear"); // 清屏
        printChristmasTree(height);
        this_thread::sleep_for(chrono::milliseconds(500)); // 暂停0.5秒
    }
}

int main() {
    int height;
    cout << "请输入圣诞树的高度: ";
    cin >> height;
    int iterations = 10; // 动态演示的次数
    animateChristmasTree(height, iterations);
    return 0;
}



