#include <iostream>
#include <math.h>
#include<stdlib.h> 
using namespace std;

typedef struct {
    int e[3];  // 固定大小的数组
} zu;

typedef struct {
    zu *T;
    int r;
    int c;
    int n;
} sss;

void output(sss &s) {
    for (int i = 0; i < s.r; i++) {
        for (int j = 0; j < s.c; j++) {
            int  found = 0;
            for (int k = 0; k < s.n; k++) {
                if (i == s.T[k].e[0] && j == s.T[k].e[1]) {
                    cout << s.T[k].e[2] << " ";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "0 ";
        }
        cout << endl;
    }
}

void fastTranspose(sss &M, sss &T) {
    // 初始化转置后的矩阵
    T.r = M.c;
    T.c = M.r;
    T.n = M.n;
    T.T = new zu[T.n];
    
    // 初始化num和cpot数组
    int *num = new int[M.c]();
    int *cpot = new int[M.c];
    
    // 计算每列非零元素个数
    for (int i = 0; i < M.n; i++) {
        num[M.T[i].e[1]]++;
    }
    
    // 计算每列第一个非零元素的位置
    cpot[0] = 0;
    for (int i = 1; i < M.c; i++) {
        cpot[i] = cpot[i-1] + num[i-1];
    }
    
    // 输出每列第一个非零元素的位置
    for (int i = 0; i < M.c; i++) {
        cout << cpot[i] << " ";
    }
    cout << endl << endl;
    
    // 执行转置
    for (int i = 0; i < M.n; i++) {
        int col = M.T[i].e[1];
        int pos = cpot[col];
        
        T.T[pos].e[0] = M.T[i].e[1];
        T.T[pos].e[1] = M.T[i].e[0];
        T.T[pos].e[2] = M.T[i].e[2];
        
        cpot[col]++;
        
        // 转置完第3个元素后输出中间结果
        if (i == 2) {
            for (int j = 0; j < T.n; j++) {
                cout << T.T[j].e[0] << " " 
                     << T.T[j].e[1] << " " 
                     << T.T[j].e[2] << endl;
            }
            cout << endl;
        }
    }
    
}

int main() {
    sss M, T;
    cin >> M.r >> M.c >> M.n;
    M.T = (zu*)malloc(M.n * sizeof(zu));
    
    for (int i = 0; i < M.n; i++) {
        cin >> M.T[i].e[0] >> M.T[i].e[1] >> M.T[i].e[2];
    }
    
    // 输出原始矩阵
    output(M);
    cout << endl;  
    // 执行快速转置
    fastTranspose(M, T); 
    // 输出转置后的矩阵
    output(T);   
    return 0;
}
