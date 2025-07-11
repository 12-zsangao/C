//【问题描述】用单链表存储一元多项式（数据结点按照指数从小到大排序），编写算法实现两个一元多项式相加。
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int c; 		// 系数
    int e; 		// 指数
    struct Node *next;
} Node;

// 创建多项式链表
Node* createPoly() {
    Node *h = (Node *)malloc(sizeof(Node)); // 创建头结点
    h->next = NULL;
    Node *t = h;
    int c, e;
    while (1) {
        scanf("%d", &c);
        if (c == -100) break;
        scanf("%d", &e);
        if (e == -100) break;
        Node *n = (Node *)malloc(sizeof(Node));
        n->c = c;
        n->e = e;
        n->next = NULL;
        t->next = n;
        t = n;
    }
    return h;
}

// 多项式相加
Node* addPoly(Node *p1, Node *p2) {
    Node *h = (Node *)malloc(sizeof(Node)); // 创建结果链表的head结点
    h->next = NULL;
    Node *t = h;
    Node *a = p1->next, *b = p2->next;

    while (a != NULL || b != NULL) {
        Node *n = (Node *)malloc(sizeof(Node));
        n->next = NULL;
        if (a == NULL) { // 只有b有剩余项
            n->c = b->c;
            n->e = b->e;
            b = b->next;
        } else if (b == NULL) { // 只有a有剩余项
            n->c = a->c;
            n->e = a->e;
            a = a->next;
        } else if (a->e < b->e) { // a的指数较小
            n->c = a->c;
            n->e = a->e;
            a = a->next;
        } else if (a->e > b->e) { // b的指数较小
            n->c = b->c;
            n->e = b->e;
            b = b->next;
        } else { // 指数相等，系数相加
            n->c = a->c + b->c;
            n->e = a->e;
            a = a->next;
            b = b->next;
        }
        // 如果系数为0，跳过该结点
        if (n->c == 0) {
            free(n);
            continue;
        }
        // 将新结点添加到结果链表中
        t->next = n;
        t = n;
    }
    return h;
}

// 输出多项式
void printPoly(Node *p) {
    Node *n = p->next;
    if (n == NULL) { // 如果链表为空，输出0
        printf("0\n");
        return;
    }
    while (n != NULL) {
        printf("%d %d", n->c, n->e);
        if (n->next != NULL) {
            printf(" ");
        }
        n = n->next;
    }
    printf("\n");
}

// 释放多项式链表
void freePoly(Node *p) {
    Node *n = p;
    while (n != NULL) {
        Node *t = n;
        n = n->next;
        free(t);
    }
}

int main() {
    Node *p1, *p2, *r;

    // 创建两个多项式链表
    p1 = createPoly();
    p2 = createPoly();
    // 多项式相加
    r = addPoly(p1, p2);
    // 输出结果
    printPoly(r);
	// 释放内存
    freePoly(p1);
    freePoly(p2);
    freePoly(r);
    return 0;
}

