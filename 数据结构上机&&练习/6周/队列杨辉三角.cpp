#include<iostream>
using namespace std;
#define MAXSIZE 20

typedef struct {
    int data[MAXSIZE];
    int front;
    int length; 
} cSqQueue;

// ����1���Ƴ���*s���壬ֱ��ʹ�ýṹ��
void InitSqQueue(cSqQueue* s) {
    s->front = 0;
    s->length = 0;
}

// ����2������Judge��������ֵ
int Judge(cSqQueue* s) {
    if(s->length == MAXSIZE) return 1; // ����
    if(s->length == 0) return 0;       // �ӿ�
    return -1;                         // �ǿշ���
}

// ����3���޸����λ�ü���
void enQueue(cSqQueue* s, int n) {
    if(Judge(s) == 1) {
        cout << "Full" << endl;
    } else {
        s->data[(s->front + s->length) % MAXSIZE] = n; // ����λ�ü���
        s->length++;
    }
}

// ����4���޸����Ӳ���
void deSqQueue(cSqQueue* s, int &x) {
    if(Judge(s) == 0) {
        cout << "Empty" << endl;
    } else {
        x = s->data[s->front];
        s->front = (s->front + 1) % MAXSIZE; // ����ȡģ����
        s->length--;
    }
}

// ������������Ǻ����㷨
void YangHUi(cSqQueue* s, int n) {
    if(n <= 0) {
        cout << "error";
        return;
    }

    InitSqQueue(s);
    enQueue(s, 1); // ��һ�е�1

    for(int i = 1; i <= n; i++) {
        int prev = 0;
        int value;
        
        // ��ӡ��ǰ��
        for(int j = 0; j < i; j++) {
            deSqQueue(s, value);
            cout << value << " ";
            
            // ������һ��Ԫ��
            if(Judge(s) != 1) {
                enQueue(s, prev + value);
            } else {
                cout << "\n��������" << endl;
                return;
            }
            prev = value;
        }
        
        // ��ĩ���1
        if(Judge(s) != 1) {
            enQueue(s, 1);
        } else {
            cout << "\n��������" << endl;
            return;
        }
        
        cout << endl;
    }
}

int main() {
    cSqQueue q;
    int n;
    cin >> n;
    
    YangHUi(&q, n);
    
    return 0;
}
