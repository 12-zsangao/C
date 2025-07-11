#include <stdio.h>
#include <stdlib.h>
// ���嵥������ṹ
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkedList;
// ��λ����
LNode* LinkedListGetINode(LinkedList L, int i) {
    LNode *p = L->next; // pָ���һ�����
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p; // ����ҵ����ص�i����㣬���򷵻�NULL
}
// ͳ�ƺ���
int LinkedListCountElement(LinkedList L, int e) {
    LNode *p = L->next; // pָ���һ�����
    int count = 0;
    while (p != NULL) {
        if (p->data == e) {
            count++;
        }
        p = p->next;
    }
    return count; // ���ص��ڸ���ֵe��Ԫ�ظ���
}
// ���뺯��
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
    LNode *q = L2->next; // qָ��L2�ĵ�һ�����
    if (q == NULL) {
        return; // ���L2Ϊ�գ�ֱ�ӷ���
    }
    LNode *r = q;
    while (r->next != NULL) {
        r = r->next;
    }
    r->next = p->next; // ��L2�����һ�����ָ��L1�ĵ�i�����
    p->next = q; // ��L1�ĵ�i-1�����ָ��L2�ĵ�һ�����
}
// ����������
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
// ���������
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




