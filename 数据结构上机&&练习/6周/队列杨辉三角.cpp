#include<iostream>
using namespace std;
#define MAXSIZE 20

typedef struct {
    int data[MAXSIZE];
    int front;
    int length; 
} cSqQueue;

// 修正1：移除了*s定义，直接使用结构体
void InitSqQueue(cSqQueue* s) {
    s->front = 0;
    s->length = 0;
}

// 修正2：完善Judge函数返回值
int Judge(cSqQueue* s) {
    if(s->length == MAXSIZE) return 1; // 队满
    if(s->length == 0) return 0;       // 队空
    return -1;                         // 非空非满
}

// 修正3：修复入队位置计算
void enQueue(cSqQueue* s, int n) {
    if(Judge(s) == 1) {
        cout << "Full" << endl;
    } else {
        s->data[(s->front + s->length) % MAXSIZE] = n; // 修正位置计算
        s->length++;
    }
}

// 修正4：修复出队操作
void deSqQueue(cSqQueue* s, int &x) {
    if(Judge(s) == 0) {
        cout << "Empty" << endl;
    } else {
        x = s->data[s->front];
        s->front = (s->front + 1) % MAXSIZE; // 增加取模运算
        s->length--;
    }
}

// 新增：杨辉三角核心算法
void YangHUi(cSqQueue* s, int n) {
    if(n <= 0) {
        cout << "error";
        return;
    }

    InitSqQueue(s);
    enQueue(s, 1); // 第一行的1

    for(int i = 1; i <= n; i++) {
        int prev = 0;
        int value;
        
        // 打印当前行
        for(int j = 0; j < i; j++) {
            deSqQueue(s, value);
            cout << value << " ";
            
            // 生成下一行元素
            if(Judge(s) != 1) {
                enQueue(s, prev + value);
            } else {
                cout << "\n队列已满" << endl;
                return;
            }
            prev = value;
        }
        
        // 行末添加1
        if(Judge(s) != 1) {
            enQueue(s, 1);
        } else {
            cout << "\n队列已满" << endl;
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
