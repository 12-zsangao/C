#include <stdio.h>
#define MAX_SIZE 100

// 定义顺序表结构
typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// 初始化顺序表
void initSeqList(SeqList *L) {
    L->length = 0;
}

// 插入元素到顺序表
void insertSeqList(SeqList *L, int element) {
    if (L->length >= MAX_SIZE) {
        printf("error\n");
        return;
    }
    L->data[L->length++] = element;
}

// 查找最小值元素并删除
int deleteMinElement(SeqList *L) {
	int i;
    if (L->length == 0) {
        printf("error\n");
        return -1;
    }
    int min = L->data[0], minIndex = 0;
    for ( i = 1; i < L->length; i++) {
        if (L->data[i] < min) {
            min = L->data[i];
            minIndex = i;
        }
    }
    for (i = minIndex; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return min;
}

// 删除给定值的所有元素
void deleteElement(SeqList *L, int e) {
    int count = 0;
    int i;
    for ( i = 0; i < L->length; i++) {
        if (L->data[i] != e) {
            L->data[count++] = L->data[i];
        }
    }
    if (count == L->length) {	//表示指定值不存在 
        printf("error\n");
    }
    L->length = count;
}

// 输出顺序表元素
void printSeqList(SeqList L) {
	int i;
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SeqList L;
    initSeqList(&L);
    int num;
    // 从键盘插入元素
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        insertSeqList(&L, num);
    }
     // 输入给定值e并删除相应元素
    int e;
    scanf("%d", &e);
    
    // 输出顺序表中的数据元素
    printSeqList(L);
    // 删除最小值元素并输出
    int min = deleteMinElement(&L);
    printf("\n%d\n", min);
    // 输出删除最小值元素之后的顺序表
    printSeqList(L);
    
    //删除具有给定值e的所有元素
    deleteElement(&L, e);
    // 输出删除给定值元素之后的顺序表
    printSeqList(L);
    return 0;
}

