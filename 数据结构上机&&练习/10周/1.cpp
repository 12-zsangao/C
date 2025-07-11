#include <iostream>
using namespace std;

#define MAX 101 
typedef struct  {
    char data;
    int lchild;
    int rchild;
    int  valid;
}Node;

Node tree[MAX];
int node_count = 1;

// 查找节点编号
int find_index(char ch) {
    for (int i = 1; i < node_count; ++i) {
        if (tree[i].valid && tree[i].data == ch)
            return i;
    }
    return -1;
}

// 查找父节点编号
int find_parent(int index) {
    for (int i = 1; i < node_count; ++i) {
        if (!tree[i].valid) continue;
        if (tree[i].lchild == index || tree[i].rchild == index)
            return i;
    }
    return -1;
}

// 删除子树
void delete_subtree(int index) {
    if (index == 0 || !tree[index].valid) return;
    delete_subtree(tree[index].lchild);
    delete_subtree(tree[index].rchild);
    tree[index].valid = false;
}

int main() {
    char ch;
    int l, r;

    // 输入
    while (cin >> ch && ch != '#') {
        cin >> l >> r;
        tree[node_count] = {ch, l, r, true};
        node_count++;
    }

    // 查询
    char q;
    cin >> q;
    int idx = find_index(q);
    if (idx == -1) {
        cout << "ERROR" << endl;
    } else {
        int parent = find_parent(idx);
        if (parent == -1)
            cout << "NO PARENT" << endl;
        else
            cout << tree[parent].data << endl;

        if (tree[idx].lchild == 0 || !tree[tree[idx].lchild].valid)
            cout << "no lchild" << endl;
        else
            cout << tree[tree[idx].lchild].data << endl;

        if (tree[idx].rchild == 0 || !tree[tree[idx].rchild].valid)
            cout << "no rchild" << endl;
        else
            cout << tree[tree[idx].rchild].data << endl;
    }

    // 删除子树
    char del;
    cin >> del;
    int del_idx = find_index(del);
    if (del_idx == -1) {
        cout << "ERROR" << endl;
    } else {
        delete_subtree(del_idx);
        int map[MAX] = {0}; 
        Node new_tree[MAX];
        int new_count = 1;
        for (int i = 1; i < node_count; ++i) {
            if (tree[i].valid) {
                map[i] = new_count;
                new_tree[new_count] = tree[i];
                ++new_count;
            }
        }

        // 更新指针
        for (int i = 1; i < new_count; ++i) {
            if (new_tree[i].lchild != 0)
                new_tree[i].lchild = map[new_tree[i].lchild];
            if (new_tree[i].rchild != 0)
                new_tree[i].rchild = map[new_tree[i].rchild];
        }

        // 输出新树
        for (int i = 1; i < new_count; ++i) {
            printf("%c %d %d\n", new_tree[i].data, new_tree[i].lchild, new_tree[i].rchild);
        }
    }

    return 0;
}

