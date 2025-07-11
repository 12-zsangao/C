#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree CreateBiTree() {
    char ch;
    scanf("%c", &ch);
    BiTree T = NULL;
    if (ch == '#') {
        T = NULL;
    } else {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
    }
    return T;
}

BiTree FindNode(BiTree T, char target) {
    if (T == NULL) return NULL;
    if (T->data == target) return T;
    BiTree left = FindNode(T->lchild, target);
    if (left != NULL) return left;
    return FindNode(T->rchild, target);
}

void FindLeftmostChild(BiTree node, int currentLevel, char *result, int *resultLevel) {
    if (node == NULL) return;
    if (node->lchild != NULL) {
        FindLeftmostChild(node->lchild, currentLevel + 1, result, resultLevel);
    } else {
        *result = node->data;
        *resultLevel = currentLevel;
    }
}

int GetNodeLevel(BiTree T, char target, int level) {
    if (T == NULL) return 0;
    if (T->data == target) return level;
    int left = GetNodeLevel(T->lchild, target, level + 1);
    if (left != 0) return left;
    return GetNodeLevel(T->rchild, target, level + 1);
}

int main() {
    BiTree T = CreateBiTree();
    
    char target;
    scanf(" %c", &target);
    
    BiTree node = FindNode(T, target);
    if (node == NULL) {
        printf("NOT EXISTED\n");
        return 0;
    }
    
    char result;
    int resultLevel;
    int nodeLevel = GetNodeLevel(T, target, 1);
    
    if (node->lchild != NULL) {
        FindLeftmostChild(node->lchild, nodeLevel + 1, &result, &resultLevel);
    } else {
        result = node->data;
        resultLevel = nodeLevel;
    }
    
    printf("%c\n%d\n", result, resultLevel);
    
    return 0;
}
