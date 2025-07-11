#include <iostream>
#include <stdlib.h>
#include <string.h> // ���� memset
using namespace std;

typedef struct { int e[3]; } zu;
typedef struct { zu *T; int r, c, n; } sss;

void output(sss &s) {
    // ��ʼ��ȫ�����
    int **matrix = (int**)malloc(s.r * sizeof(int*));
    for (int i = 0; i < s.r; i++) {
        matrix[i] = (int*)calloc(s.c, sizeof(int)); // �Զ���ʼ��Ϊ0
    }

    // ������Ԫ��
    for (int k = 0; k < s.n; k++) {
        int i = s.T[k].e[0];
        int j = s.T[k].e[1];
        matrix[i][j] = s.T[k].e[2];
    }

    // �������
    for (int i = 0; i < s.r; i++) {
        for (int j = 0; j < s.c; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // �ͷ��ڴ�
    for (int i = 0; i < s.r; i++) free(matrix[i]);
    free(matrix);
}

void fastTranspose(sss &M, sss &T) {
    T.r = M.c;
    T.c = M.r;
    T.n = M.n;
    T.T = (zu*)malloc(T.n * sizeof(zu));
    memset(T.T, 0, T.n * sizeof(zu)); // ��ʽ��ʼ��Ϊ0

    int *num = (int*)calloc(M.c, sizeof(int)); // �Զ���ʼ��Ϊ0
    int *cpot = (int*)malloc(M.c * sizeof(int));

    // ͳ��ÿ�з���Ԫ�ظ���
    for (int i = 0; i < M.n; i++) {
        num[M.T[i].e[1]]++;
    }

    // ������ʼλ��
    cpot[0] = 0;
    for (int i = 1; i < M.c; i++) {
        cpot[i] = cpot[i-1] + num[i-1];
    }

    // �����ʼλ�ã���ĿҪ��
    for (int i = 0; i < M.c; i++) cout << cpot[i] << " ";
    cout << endl << endl;

    // ִ��ת��
    for (int i = 0; i < M.n; i++) {
        int col = M.T[i].e[1];
        int pos = cpot[col];

        T.T[pos].e[0] = M.T[i].e[1]; // ��=ԭ��
        T.T[pos].e[1] = M.T[i].e[0]; // ��=ԭ��
        T.T[pos].e[2] = M.T[i].e[2]; // ֵ����

        cpot[col]++;

        // ����м�������ĿҪ��
        if (i == 2) {
            for (int j = 0; j < T.n; j++) {
                cout << T.T[j].e[0] << " " 
                     << T.T[j].e[1] << " " 
                     << T.T[j].e[2] << endl;
            }
            cout << endl;
        }
    }

    free(num);
    free(cpot);
}

int main() {
    sss M, T;
    cin >> M.r >> M.c >> M.n;

    M.T = (zu*)malloc(M.n * sizeof(zu));
    memset(M.T, 0, M.n * sizeof(zu)); // ��ʽ��ʼ��Ϊ0

    for (int i = 0; i < M.n; i++) {
        cin >> M.T[i].e[0] >> M.T[i].e[1] >> M.T[i].e[2];
    }

    // ���ԭʼ����
    output(M);
    cout << endl;

    // ִ��ת��
    fastTranspose(M, T);

    // ���ת�þ���
    output(T);

    free(M.T);
    free(T.T);
    return 0;
}
