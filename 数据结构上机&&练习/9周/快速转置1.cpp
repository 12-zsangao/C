#include <iostream>
#include <math.h>
#include<stdlib.h> 
using namespace std;

typedef struct {
    int e[3];  // �̶���С������
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
    // ��ʼ��ת�ú�ľ���
    T.r = M.c;
    T.c = M.r;
    T.n = M.n;
    T.T = new zu[T.n];
    
    // ��ʼ��num��cpot����
    int *num = new int[M.c]();
    int *cpot = new int[M.c];
    
    // ����ÿ�з���Ԫ�ظ���
    for (int i = 0; i < M.n; i++) {
        num[M.T[i].e[1]]++;
    }
    
    // ����ÿ�е�һ������Ԫ�ص�λ��
    cpot[0] = 0;
    for (int i = 1; i < M.c; i++) {
        cpot[i] = cpot[i-1] + num[i-1];
    }
    
    // ���ÿ�е�һ������Ԫ�ص�λ��
    for (int i = 0; i < M.c; i++) {
        cout << cpot[i] << " ";
    }
    cout << endl << endl;
    
    // ִ��ת��
    for (int i = 0; i < M.n; i++) {
        int col = M.T[i].e[1];
        int pos = cpot[col];
        
        T.T[pos].e[0] = M.T[i].e[1];
        T.T[pos].e[1] = M.T[i].e[0];
        T.T[pos].e[2] = M.T[i].e[2];
        
        cpot[col]++;
        
        // ת�����3��Ԫ�غ�����м���
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
    
    // ���ԭʼ����
    output(M);
    cout << endl;  
    // ִ�п���ת��
    fastTranspose(M, T); 
    // ���ת�ú�ľ���
    output(T);   
    return 0;
}
