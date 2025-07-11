#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 用于层次遍历的队列
typedef struct Queue {
    TreeNode* data[100];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

// 入队
void enqueue(Queue* q, TreeNode* node) {
    if ((q->rear + 1) % 100 != q->front) {
        q->data[q->rear] = node;
        q->rear = (q->rear + 1) % 100;
    }
}

// 出队
TreeNode* dequeue(Queue* q) {
    if (q->front != q->rear) {
        TreeNode* temp = q->data[q->front];
        q->front = (q->front + 1) % 100;
        return temp;
    }
    return NULL;
}

// 队列是否为空
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// 构建二叉树（先序带#）
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

// 层次遍历并判断是否为完全二叉树
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

