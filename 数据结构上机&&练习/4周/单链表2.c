#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 定义链表结构
typedef struct {
    Node *head;
} LinkedList;

// 初始化链表
void initList(LinkedList *list) {
    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL;
}

// 插入函数
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

// 删除函数
void deleteNode(LinkedList *list, int e) {
    Node *current = list->head;
    //没找到要在最后一个节点停下，// 找到节点e之前1个节点结束循环 
    while (current->next != NULL && current->next->data != e) {
        current = current->next;
    }
    if (current->next != NULL) {
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// 输出链表
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

