#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
typedef struct TreeNode {
    int val;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

// 创建新节点
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

// 插入元素到BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->val)
        root->lchild = insert(root->lchild, val);
    else if (val > root->val)
        root->rchild = insert(root->rchild, val);
    // 如果相等，不插入
    return root;
}

// 打印树的括号形式
void printTree(TreeNode* root) {
    if (root == NULL) return;
    printf("%d", root->val);
    if (root->lchild == NULL && root->rchild == NULL)
        return;
    printf("(");
    if (root->lchild)
        printTree(root->lchild);
    printf(",");
    if (root->rchild)
        printTree(root->rchild);
    printf(")");
}

// 查找路径
void search(TreeNode* root, int target) {
    while (root) {
        printf("%d", root->val);
        if (root->val == target) break;
        printf(" ");
        if (target < root->val)
            root = root->lchild;
        else
            root = root->rchild;
    }
}

int main() {
	 int nums[MAXN], cnt = 0, val;
    TreeNode* root = NULL;
    // 先读取所有插入值（以 -1 结束）
    while (scanf("%d", &val) && val != -1) {
        nums[cnt++] = val;
    }
    // 然后输入要查找的值
    int target;
    scanf("%d", &target); 
    // 逐个插入并打印树结构
    for (int i = 0; i < cnt; ++i) {
        root = insert(root, nums[i]);
        printTree(root);
        printf("\n");
    }
    search(root, target);
    printf("\n");
    return 0;
}

