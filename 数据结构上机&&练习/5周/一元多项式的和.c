//�������������õ�����洢һԪ����ʽ�����ݽ�㰴��ָ����С�������򣩣���д�㷨ʵ������һԪ����ʽ��ӡ�
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int c; 		// ϵ��
    int e; 		// ָ��
    struct Node *next;
} Node;

// ��������ʽ����
Node* createPoly() {
    Node *h = (Node *)malloc(sizeof(Node)); // ����ͷ���
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

// ����ʽ���
Node* addPoly(Node *p1, Node *p2) {
    Node *h = (Node *)malloc(sizeof(Node)); // ������������head���
    h->next = NULL;
    Node *t = h;
    Node *a = p1->next, *b = p2->next;

    while (a != NULL || b != NULL) {
        Node *n = (Node *)malloc(sizeof(Node));
        n->next = NULL;
        if (a == NULL) { // ֻ��b��ʣ����
            n->c = b->c;
            n->e = b->e;
            b = b->next;
        } else if (b == NULL) { // ֻ��a��ʣ����
            n->c = a->c;
            n->e = a->e;
            a = a->next;
        } else if (a->e < b->e) { // a��ָ����С
            n->c = a->c;
            n->e = a->e;
            a = a->next;
        } else if (a->e > b->e) { // b��ָ����С
            n->c = b->c;
            n->e = b->e;
            b = b->next;
        } else { // ָ����ȣ�ϵ�����
            n->c = a->c + b->c;
            n->e = a->e;
            a = a->next;
            b = b->next;
        }
        // ���ϵ��Ϊ0�������ý��
        if (n->c == 0) {
            free(n);
            continue;
        }
        // ���½����ӵ����������
        t->next = n;
        t = n;
    }
    return h;
}

// �������ʽ
void printPoly(Node *p) {
    Node *n = p->next;
    if (n == NULL) { // �������Ϊ�գ����0
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

// �ͷŶ���ʽ����
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

    // ������������ʽ����
    p1 = createPoly();
    p2 = createPoly();
    // ����ʽ���
    r = addPoly(p1, p2);
    // ������
    printPoly(r);
	// �ͷ��ڴ�
    freePoly(p1);
    freePoly(p2);
    freePoly(r);
    return 0;
}

