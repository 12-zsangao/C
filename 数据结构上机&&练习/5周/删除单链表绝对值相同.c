/*【问题描述】用单链表保存n个整数，结点结构为：data数据域 next指针域；且|data|<=n (n为问题规模，正整数）
请设计算法，对于链表中data的绝对值相等的结点，仅仅保留第一次出现的结点而删除绝对值相等的结点。
请尽设计一个时间复杂度尽可能高效的算法。*/
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
    
    while (curr!=NULL)				//时间复杂度为O(n) 
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


