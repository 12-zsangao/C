/*【问题描述】给定一个带头结点的单链表，在不改变单链表的前提下，设计一个尽可能高效的算法，查找链表中倒数第K个位置上的结点（K为正整数），若查找成功，输出该结点的data域的值，返回1；否则，返回0；   
注意：请自行分析时间复杂度和空间复杂度，作为注释附在程序代码中提交
本题算法时间复杂度O（n），空间复杂度O（1），并且扫描一次链表就可以完成查找。*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LinkNode;

// 建立单链表
LinkNode* ListCreate() {
    LinkNode *head, *tail, *s;
    int x;
    head = (LinkNode *)malloc(sizeof(LinkNode)); // 创建头结点
    head->next = NULL;
    tail = head;
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = x;
        s->next = NULL;
        tail->next = s;
        tail = s;
    }
    return head;
}

// 输出单链表
void printList(LinkNode *L) {
    LinkNode *p = L->next;
    while (p) {
        printf("%d", p->data);
        if (p->next) {
            printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}

// 查找倒数第K个结点
int locate_k(LinkNode *L, int k) {                   //未用嵌套循环，时间复杂度为O(n),定义变量与n无关，空间复杂度O(1)
    if (k <= 0) { // k必须为正整数
        return 0;
    }

    LinkNode *p = L, *q = L; // 初始化两个指针，都指向头结点
    int count = 0;

    // p移动K步
    while (p != NULL && count < k) {
        p = p->next;
        count++;
    }
    // if链表长度小于K，返回0
    if (count < k) {
        return 0;
    }
    // p和q同时移动，直到p到达链表末尾
    while (p != NULL) {
        p = p->next;
        q = q->next;
    }

    printf("%d\n", q->data);
    return 1;
}
int main() {
    LinkNode *L;
    int k;
    L = ListCreate(); // 创建链表
    scanf("%d", &k);  // 输入K的值
    if (locate_k(L, k) == 0) {
        printf("error\n"); // 如果查找失败，输出error
    }
    free(L); // 释放链表内存
    return 0;
}





