#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// ��������������й���������
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

// ������Ϊ 2 �Ľڵ����������
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

// �������������
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

// ����������ĸ߶�
int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

// ͳ�����������߶���ȵĽڵ���
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

// �ͷŶ������ڴ�
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
