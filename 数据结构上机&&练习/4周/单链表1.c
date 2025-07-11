#include <stdio.h>
#include <stdlib.h>
// 定义单链表结点结构
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkedList;
// 定位函数
LNode* LinkedListGetINode(LinkedList L, int i) {
    LNode *p = L->next; // p指向第一个结点
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p; // 如果找到返回第i个结点，否则返回NULL
}
// 统计函数
int LinkedListCountElement(LinkedList L, int e) {
    LNode *p = L->next; // p指向第一个结点
    int count = 0;
    while (p != NULL) {
        if (p->data == e) {
            count++;
        }
        p = p->next;
    }
    return count; // 返回等于给定值e的元素个数
}
// 插入函数
void LinkedListInsertList(LinkedList L1, int i, LinkedList L2) {
    LNode *p = L1;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        printf("error  \n");
        return;
    }
    LNode *q = L2->next; // q指向L2的第一个结点
    if (q == NULL) {
        return; // 如果L2为空，直接返回
    }
    LNode *r = q;
    while (r->next != NULL) {
        r = r->next;
    }
    r->next = p->next; // 将L2的最后一个结点指向L1的第i个结点
    p->next = q; // 将L1的第i-1个结点指向L2的第一个结点
}
// 创建单链表
LinkedList createLinkedList(int n) {
    LinkedList head = (LinkedList)malloc(sizeof(LNode));
    head->next = NULL;
    LNode *tail = head;
    int i; 
    for ( i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        LNode *newNode = (LNode*)malloc(sizeof(LNode));
        newNode->data = data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}
// 输出单链表
void printLinkedList(LinkedList L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main() {
    int n1;
    scanf("%d", &n1);
    LinkedList L1 = createLinkedList(n1);
    printLinkedList(L1);
    int i;
    scanf("%d", &i);
    LNode *node = LinkedListGetINode(L1, i);
    if (node == NULL) {
        printf("error\n");
    } else {
        printf("%d\n", node->data);
    }
    int n2;
    scanf("%d", &n2);
    LinkedList L2 = createLinkedList(n2);
    printLinkedList(L2);
    scanf("%d", &i);
    LinkedListInsertList(L1, i, L2);
    printLinkedList(L1);
    int e;
    scanf("%d", &e);
    int count = LinkedListCountElement(L1, e);
    printf("%d\n", count);
    return 0;
}




