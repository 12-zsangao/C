#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// ��������ṹ
typedef struct {
    Node *head;
} LinkedList;

// ��ʼ������
void initList(LinkedList *list) {
    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL;
}

// ���뺯��
void insert(LinkedList *list, int e) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = e;
    Node *current = list->head;
    while (current->next != NULL && current->next->data < e) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// ɾ������
void deleteNode(LinkedList *list, int e) {
    Node *current = list->head;
    //û�ҵ�Ҫ�����һ���ڵ�ͣ�£�// �ҵ��ڵ�e֮ǰ1���ڵ����ѭ�� 
    while (current->next != NULL && current->next->data != e) {
        current = current->next;
    }
    if (current->next != NULL) {
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// �������
void printList(LinkedList *list) {
    Node *current = list->head->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    initList(&list);

    int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        insert(&list, num);
    }
    printList(&list);

    scanf("%d", &num);
    insert(&list, num);
    printList(&list);

    scanf("%d", &num);
    deleteNode(&list, num);
    printList(&list);

    return 0;
}

