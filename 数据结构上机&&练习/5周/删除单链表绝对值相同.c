/*�������������õ�������n�����������ṹΪ��data������ nextָ������|data|<=n (nΪ�����ģ����������
������㷨������������data�ľ���ֵ��ȵĽ�㣬����������һ�γ��ֵĽ���ɾ������ֵ��ȵĽ�㡣
�뾡���һ��ʱ�临�ӶȾ����ܸ�Ч���㷨��*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LinkNode;
LinkNode* ListCreate()
{
    LinkNode *head;
    head = (LinkNode *)malloc(sizeof(LinkNode));
    head->next = NULL;
    LinkNode *p = head, *tail = head, *s;
    int x;
    
    while (1)
    {
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
void printList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p)
    {
        printf("%d", p->data);
        if (p->next) {
            printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}
void deleteElem(LinkNode *L)
{
    int i;
    int *num = (int*)malloc(1001*sizeof(int)); 
    for(i=0;i<1001;i++)    num[i]=0;
    LinkNode *curr = L->next, *pre = L;
    
    while (curr!=NULL)				//ʱ�临�Ӷ�ΪO(n) 
    {
        int x = abs(curr->data);
        if (num[x] == 0) {
            num[x] = 1;
            pre = curr;
            curr = curr->next;
        } else {
            pre->next = curr->next;
            LinkNode *t = curr;
            curr = curr->next;
            free(t);
        }
    }
    free(num); 
}

int main()
{
    LinkNode *L;
    L = ListCreate();
    deleteElem(L);
    printList(L);
    LinkNode *p = L;
    while (p) {
        LinkNode *temp = p;
        p = p->next;
        free(temp);
    }
    return 0;
}


