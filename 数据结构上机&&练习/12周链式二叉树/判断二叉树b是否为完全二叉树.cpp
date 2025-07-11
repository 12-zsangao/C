#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ���ڲ�α����Ķ���
typedef struct Queue {
    TreeNode* data[100];
    int front, rear;
} Queue;

// ��ʼ������
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

// ���
void enqueue(Queue* q, TreeNode* node) {
    if ((q->rear + 1) % 100 != q->front) {
        q->data[q->rear] = node;
        q->rear = (q->rear + 1) % 100;
    }
}

// ����
TreeNode* dequeue(Queue* q) {
    if (q->front != q->rear) {
        TreeNode* temp = q->data[q->front];
        q->front = (q->front + 1) % 100;
        return temp;
    }
    return NULL;
}

// �����Ƿ�Ϊ��
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// �����������������#��
TreeNode* buildTree(char* str, int* index) {
    if (str[*index] == '\0') return NULL;
    char ch = str[*index];
    (*index)++;
    if (ch == '#') return NULL;

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = ch;
    node->left = buildTree(str, index);
    node->right = buildTree(str, index);
    return node;
}

// ��α������ж��Ƿ�Ϊ��ȫ������
int levelOrderAndCheck(TreeNode* root) {
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    int isComplete = 1;
    int encounteredNull = 0;

    while (!isEmpty(&q)) {
        TreeNode* curr = dequeue(&q);
        if (curr) {
            printf("%c", curr->data);
            if (encounteredNull) isComplete = 0;
            enqueue(&q, curr->left);
            enqueue(&q, curr->right);
        } else {
            encounteredNull = 1;
        }
    }

    printf("\n");
    return isComplete;
}

int main() {
    char str[100];
    scanf("%s", str);
    int index = 0;
    TreeNode* root = buildTree(str, &index);

    int isComplete = levelOrderAndCheck(root);
    if (isComplete)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

