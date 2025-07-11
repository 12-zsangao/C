#include <stdio.h>
#define MAX_SIZE 100

// ����˳���ṹ
typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// ��ʼ��˳���
void initSeqList(SeqList *L) {
    L->length = 0;
}

// ����Ԫ�ص�˳���
void insertSeqList(SeqList *L, int element) {
    if (L->length >= MAX_SIZE) {
        printf("error\n");
        return;
    }
    L->data[L->length++] = element;
}

// ������СֵԪ�ز�ɾ��
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

// ɾ������ֵ������Ԫ��
void deleteElement(SeqList *L, int e) {
    int count = 0;
    int i;
    for ( i = 0; i < L->length; i++) {
        if (L->data[i] != e) {
            L->data[count++] = L->data[i];
        }
    }
    if (count == L->length) {	//��ʾָ��ֵ������ 
        printf("error\n");
    }
    L->length = count;
}

// ���˳���Ԫ��
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
    // �Ӽ��̲���Ԫ��
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        insertSeqList(&L, num);
    }
     // �������ֵe��ɾ����ӦԪ��
    int e;
    scanf("%d", &e);
    
    // ���˳����е�����Ԫ��
    printSeqList(L);
    // ɾ����СֵԪ�ز����
    int min = deleteMinElement(&L);
    printf("\n%d\n", min);
    // ���ɾ����СֵԪ��֮���˳���
    printSeqList(L);
    
    //ɾ�����и���ֵe������Ԫ��
    deleteElement(&L, e);
    // ���ɾ������ֵԪ��֮���˳���
    printSeqList(L);
    return 0;
}

