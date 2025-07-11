/*����������������һ����ͷ���ĵ������ڲ��ı䵥�����ǰ���£����һ�������ܸ�Ч���㷨�����������е�����K��λ���ϵĽ�㣨KΪ���������������ҳɹ�������ý���data���ֵ������1�����򣬷���0��   
ע�⣺�����з���ʱ�临�ӶȺͿռ临�Ӷȣ���Ϊע�͸��ڳ���������ύ
�����㷨ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1��������ɨ��һ������Ϳ�����ɲ��ҡ�*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LinkNode;

// ����������
LinkNode* ListCreate() {
    LinkNode *head, *tail, *s;
    int x;
    head = (LinkNode *)malloc(sizeof(LinkNode)); // ����ͷ���
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

// ���������
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

// ���ҵ�����K�����
int locate_k(LinkNode *L, int k) {                   //δ��Ƕ��ѭ����ʱ�临�Ӷ�ΪO(n),���������n�޹أ��ռ临�Ӷ�O(1)
    if (k <= 0) { // k����Ϊ������
        return 0;
    }

    LinkNode *p = L, *q = L; // ��ʼ������ָ�룬��ָ��ͷ���
    int count = 0;

    // p�ƶ�K��
    while (p != NULL && count < k) {
        p = p->next;
        count++;
    }
    // if������С��K������0
    if (count < k) {
        return 0;
    }
    // p��qͬʱ�ƶ���ֱ��p��������ĩβ
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
    L = ListCreate(); // ��������
    scanf("%d", &k);  // ����K��ֵ
    if (locate_k(L, k) == 0) {
        printf("error\n"); // �������ʧ�ܣ����error
    }
    free(L); // �ͷ������ڴ�
    return 0;
}





