#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// 根据先序遍历序列构建二叉树
Node* build() {
    char c;
    scanf("%c", &c);
    if (c == '#') {
        return NULL;
    }
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = c;
    node->left = build();
    node->right = build();
    return node;
}

// 交换度为 2 的节点的左右子树
void swap(Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->left && root->right) {
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    swap(root->left);
    swap(root->right);
}

// 中序遍历二叉树
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

// 计算二叉树的高度
int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

// 统计左右子树高度相等的节点数
int count(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);
    int cnt = count(root->left) + count(root->right);
    if (leftH == rightH) {
        cnt++;
    }
    return cnt;
}

// 释放二叉树内存
void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = build();
    swap(root);
    inorder(root);
    printf("\n");
    int equalCount = count(root);
    printf("%d\n", equalCount);
    freeTree(root);
    return 0;
}    
