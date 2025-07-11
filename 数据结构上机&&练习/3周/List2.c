#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义有序顺序表结构体
typedef struct {
    int data[MAX_SIZE];
    int length;
} OrderedSeqList;

// 初始化顺序表
void initList(OrderedSeqList *list) {
    list->length = 0;
}

// 插入元素到有序表中
void insert(OrderedSeqList *list, int e) {
    int i;
    if (list->length == MAX_SIZE) {
        printf("顺序表已满，无法插入！\n");
        return;
    }
    for (i = list->length - 1; i >= 0 && list->data[i] > e; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[i + 1] = e;
    list->length++;
}

// 删除值为e的所有数据元素
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

// 合并两个有序表
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

// 删除给定范围的元素
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

// 输出顺序表元素
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

    // 步骤1：输入若干个数，-1表示输入结束
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        insert(&list1, num);
    }

    // 步骤2：输出有序顺序表的数据元素
    printList(&list1);

    // 步骤3：删除值为e的所有数据元素
    int e;
    scanf("%d", &e);
    deleteElement(&list1, e);

    // 步骤4：输入若干个数，-1表示输入结束，存放至第二个有序顺序表中
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        insert(&list2, num);
    }

    // 步骤5：合并这两个有序顺序表
    mergeLists(&list1, &list2, &mergedList);

    // 步骤6：输出合并后的有序顺序表
    printList(&mergedList);

    // 步骤7：删除第6步骤中给定范围的元素
    int s, t;
    scanf("%d %d", &s, &t);
    deleteRange(&mergedList, s, t);

    // 步骤8：输出删除后的顺序表
    printList(&mergedList);

    return 0;
}
