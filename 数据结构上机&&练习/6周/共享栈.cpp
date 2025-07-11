#include <stdio.h>
#define MAXSIZE 12  

typedef struct {
    int data[MAXSIZE];  
    int top1;           
    int top2;          
} SharedStack;

// 初始化共享栈
void InitStack(SharedStack *s) {
    s->top1 = -1;       
    s->top2 = MAXSIZE;  
}

// 判断栈1是否为空
int IsEmpty1(SharedStack *s) {
    return s->top1 == -1;
}

// 判断栈2是否为空
int IsEmpty2(SharedStack *s) {
    return s->top2 == MAXSIZE;
}

// 判断共享栈是否已满
int IsFull(SharedStack *s) {
    return s->top1 + 1 >= s->top2;
}

// 栈1入栈
void Push1(SharedStack *s, int x) {
    if (IsFull(s)) {
        printf("full\n");
        return;
    }
    s->data[++s->top1] = x;
}

// 栈2入栈
void Push2(SharedStack *s, int x) {
    if (IsFull(s)) {
        printf("full\n");
        return;
    }
    s->data[--s->top2] = x;
}

// 栈1出栈
int Pop1(SharedStack *s) {
    if (IsEmpty1(s)) {
        return -1;  // 返回-1表示出错
    }
    return s->data[s->top1--];
}

// 栈2出栈
int Pop2(SharedStack *s) {
    if (IsEmpty2(s)) {
        return -1;  // 返回-1表示出错
    }
    return s->data[s->top2++];
}

// 输出栈1(顶到底 
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

// 输出栈2（顶到底 
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
    PrintStack1(&s);		// 初始状态输出
    PrintStack2(&s);
    int n;
    scanf("%d", &n);
    
    if (n < 0) {
        printf("error\n");	//处理负值 
        PrintStack1(&s);
        PrintStack2(&s);
        return 0;
    }
    // 奇数入栈1
    for (int i = 1; i < n; i += 2) {
        if (IsFull(&s)) {
            printf("full\n");
            break;
        }
        Push1(&s, i);
    }
    //偶数入栈2
    for (int i = 2; i < n; i += 2) {
        if (IsFull(&s)) {
            printf("full\n");
            break;
        }
        Push2(&s, i);
    }
    // 栈1出顶栈并输出
    int val1 = Pop1(&s);
    if (val1 != -1) {
        printf("%d\n", val1);
    }
    // 栈2顶出栈并输出
    int val2 = Pop2(&s);
    if (val2 != -1) {
        printf("%d\n", val2);
    }
    PrintStack1(&s);		// 最终输出
    PrintStack2(&s);
    
  return 0;
}
