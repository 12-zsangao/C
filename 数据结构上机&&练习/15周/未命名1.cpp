#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 插入BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// 计算最大宽度和查找k所在层次
int maxWidth(TreeNode* root, int k, int* k_level) {
    if (!root) return 0;
    TreeNode* queue[1000];
    int level[1000];
    int front = 0, rear = 0;
    queue[rear] = root;
    level[rear++] = 1;

    int level_count[100] = {0};
    int max_width = 0;
    *k_level = -1;

    while (front < rear) {
        TreeNode* node = queue[front];
        int l = level[front++];
        level_count[l]++;
        if (node->val == k)
            *k_level = l;

        if (node->left) {
            queue[rear] = node->left;
            level[rear++] = l + 1;
        }
        if (node->right) {
            queue[rear] = node->right;
            level[rear++] = l + 1;
        }
    }

    for (int i = 1; i < 100; i++) {
        if (level_count[i] > max_width)
            max_width = level_count[i];
    }
    return max_width;
}

// 中序遍历输出所有不小于k的值（仅当k存在于树中时）
void inorder(TreeNode* root, int k, int k_level) {
    if (!root) return;
    if (k_level == -1) return;  // 如果k不在树中，直接返回，不打印任何内容
    
    inorder(root->left, k, k_level);
    if (root->val >= k)
        printf("%d ", root->val);
    inorder(root->right, k, k_level);
}

int main() {
    int x, k;
    TreeNode* root = NULL;

    // 输入构建BST
    while (scanf("%d", &x) && x != -1) {
        root = insert(root, x);
    }
    scanf("%d", &k);
    
    // 宽度和k的层次
    int k_level;
    int width = maxWidth(root, k, &k_level);
    if (k_level == -1)
        printf("%d NONE\n", width);
    else
        printf("%d %d\n", width, k_level);
    
    // 输出不小于k的值（升序），仅当k存在时
    inorder(root, k, k_level);
    printf("\n"); 
    return 0;
}

