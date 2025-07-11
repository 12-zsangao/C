#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �������������#��
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

// ����ֵΪx�Ľڵ�
TreeNode* findNode(TreeNode* root, char x) {
    if (!root) return NULL;
    if (root->data == x) return root;
    TreeNode* left = findNode(root->left, x);
    if (left) return left;
    return findNode(root->right, x);
}

// �����������������㣩
void preorder(TreeNode* root) {
    if (!root) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    char str[100];
    char x;
    scanf("%s", str);
    getchar(); // ��ȡ����
    scanf("%c", &x);

    int index = 0;
    TreeNode* root = buildTree(str, &index);

    TreeNode* target = findNode(root, x);
    if (!target) {
        printf("NONE\n");
    } else if (!target->left && !target->right) {
        printf("NULL\n");
    } else {
        if (target->left) preorder(target->left);
        if (target->right) preorder(target->right);
        printf("\n");
    }

    return 0;
}

