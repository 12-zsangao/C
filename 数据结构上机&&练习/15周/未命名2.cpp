#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
typedef struct TreeNode {
    int val;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

// ����Ԫ�ص�BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->val)
        root->lchild = insert(root->lchild, val);
    else if (val > root->val)
        root->rchild = insert(root->rchild, val);
    // �����ȣ�������
    return root;
}

// ��ӡ����������ʽ
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

// ����·��
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
    // �ȶ�ȡ���в���ֵ���� -1 ������
    while (scanf("%d", &val) && val != -1) {
        nums[cnt++] = val;
    }
    // Ȼ������Ҫ���ҵ�ֵ
    int target;
    scanf("%d", &target); 
    // ������벢��ӡ���ṹ
    for (int i = 0; i < cnt; ++i) {
        root = insert(root, nums[i]);
        printTree(root);
        printf("\n");
    }
    search(root, target);
    printf("\n");
    return 0;
}

