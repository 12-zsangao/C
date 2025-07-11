#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// ��������˳���ṹ��
typedef struct {
    int data[MAX_SIZE];
    int length;
} OrderedSeqList;

// ��ʼ��˳���
void initList(OrderedSeqList *list) {
    list->length = 0;
}

// ����Ԫ�ص��������
void insert(OrderedSeqList *list, int e) {
    int i;
    if (list->length == MAX_SIZE) {
        printf("˳����������޷����룡\n");
        return;
    }
    for (i = list->length - 1; i >= 0 && list->data[i] > e; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[i + 1] = e;
    list->length++;
}

// ɾ��ֵΪe����������Ԫ��
void deleteElement(OrderedSeqList *list, int e) {
    int i, j = 0;
    int found = 0;
    if (list->length == 0) {
        printf("empty list\n");
        return;
    }
    for (i = 0; i < list->length; i++) {
        if (list->data[i] != e) {
            list->data[j] = list->data[i];
            j++;
        } else {
            found = 1;
        }
    }
    if (!found) {
        printf("error\n");
    }
    list->length = j;
}

// �ϲ����������
void mergeLists(OrderedSeqList *list1, OrderedSeqList *list2, OrderedSeqList *result) {
    int i = 0, j = 0, k = 0;
    while (i < list1->length && j < list2->length) {
        if (list1->data[i] < list2->data[j]) {
            result->data[k++] = list1->data[i++];
        } else {
            result->data[k++] = list2->data[j++];
        }
    }
    while (i < list1->length) {
        result->data[k++] = list1->data[i++];
    }
    while (j < list2->length) {
        result->data[k++] = list2->data[j++];
    }
    result->length = k;
}

// ɾ��������Χ��Ԫ��
void deleteRange(OrderedSeqList *list, int s, int t) {
    if (s >= t || list->length == 0) {
        if (list->length == 0) {
            printf("empty list\n");
        } else {
            printf("error\n");
        }
        exit(1);
    }
    int i, j = 0;
    for (i = 0; i < list->length; i++) {
        if (list->data[i] < s || list->data[i] >= t) {
            list->data[j] = list->data[i];
            j++;
        }
    }
    list->length = j;
}

// ���˳���Ԫ��
void printList(OrderedSeqList *list) {
    if (list->length == 0) {
        printf("empty list\n");
        return;
    }
    int i;
    for ( i = 0; i < list->length; i++) {
        printf("%d", list->data[i]);
        if (i < list->length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    OrderedSeqList list1, list2, mergedList;
    initList(&list1);
    initList(&list2);
    initList(&mergedList);

    // ����1���������ɸ�����-1��ʾ�������
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        insert(&list1, num);
    }

    // ����2���������˳��������Ԫ��
    printList(&list1);

    // ����3��ɾ��ֵΪe����������Ԫ��
    int e;
    scanf("%d", &e);
    deleteElement(&list1, e);

    // ����4���������ɸ�����-1��ʾ���������������ڶ�������˳�����
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        insert(&list2, num);
    }

    // ����5���ϲ�����������˳���
    mergeLists(&list1, &list2, &mergedList);

    // ����6������ϲ��������˳���
    printList(&mergedList);

    // ����7��ɾ����6�����и�����Χ��Ԫ��
    int s, t;
    scanf("%d %d", &s, &t);
    deleteRange(&mergedList, s, t);

    // ����8�����ɾ�����˳���
    printList(&mergedList);

    return 0;
}
