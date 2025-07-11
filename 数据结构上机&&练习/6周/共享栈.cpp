#include <stdio.h>
#define MAXSIZE 12  

typedef struct {
    int data[MAXSIZE];  
    int top1;           
    int top2;          
} SharedStack;

// ��ʼ������ջ
void InitStack(SharedStack *s) {
    s->top1 = -1;       
    s->top2 = MAXSIZE;  
}

// �ж�ջ1�Ƿ�Ϊ��
int IsEmpty1(SharedStack *s) {
    return s->top1 == -1;
}

// �ж�ջ2�Ƿ�Ϊ��
int IsEmpty2(SharedStack *s) {
    return s->top2 == MAXSIZE;
}

// �жϹ���ջ�Ƿ�����
int IsFull(SharedStack *s) {
    return s->top1 + 1 >= s->top2;
}

// ջ1��ջ
void Push1(SharedStack *s, int x) {
    if (IsFull(s)) {
        printf("full\n");
        return;
    }
    s->data[++s->top1] = x;
}

// ջ2��ջ
void Push2(SharedStack *s, int x) {
    if (IsFull(s)) {
        printf("full\n");
        return;
    }
    s->data[--s->top2] = x;
}

// ջ1��ջ
int Pop1(SharedStack *s) {
    if (IsEmpty1(s)) {
        return -1;  // ����-1��ʾ����
    }
    return s->data[s->top1--];
}

// ջ2��ջ
int Pop2(SharedStack *s) {
    if (IsEmpty2(s)) {
        return -1;  // ����-1��ʾ����
    }
    return s->data[s->top2++];
}

// ���ջ1(������ 
void PrintStack1(SharedStack *s) {
    if (IsEmpty1(s)) {
        printf("stack1:empty\n");
        return;
    }
    printf("stack1:");
    for (int i = s->top1; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// ���ջ2�������� 
void PrintStack2(SharedStack *s) {
    if (IsEmpty2(s)) {
        printf("stack2:empty\n");
        return;
    }
    printf("stack2:");
    for (int i = s->top2; i < MAXSIZE; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    SharedStack s;
    InitStack(&s);
    PrintStack1(&s);		// ��ʼ״̬���
    PrintStack2(&s);
    int n;
    scanf("%d", &n);
    
    if (n < 0) {
        printf("error\n");	//����ֵ 
        PrintStack1(&s);
        PrintStack2(&s);
        return 0;
    }
    // ������ջ1
    for (int i = 1; i < n; i += 2) {
        if (IsFull(&s)) {
            printf("full\n");
            break;
        }
        Push1(&s, i);
    }
    //ż����ջ2
    for (int i = 2; i < n; i += 2) {
        if (IsFull(&s)) {
            printf("full\n");
            break;
        }
        Push2(&s, i);
    }
    // ջ1����ջ�����
    int val1 = Pop1(&s);
    if (val1 != -1) {
        printf("%d\n", val1);
    }
    // ջ2����ջ�����
    int val2 = Pop2(&s);
    if (val2 != -1) {
        printf("%d\n", val2);
    }
    PrintStack1(&s);		// �������
    PrintStack2(&s);
    
  return 0;
}
