#include <stdio.h>
#define MAXV 100
typedef struct {
    char vertex[MAXV];
    int adj[MAXV][MAXV];
    int n;
} MGraph;

int main() {
    MGraph G;
    G.n = 0;
    char ch;
    // 输入顶点
    while ((ch = getchar()) != '!') {
        G.vertex[G.n++] = ch;
    }
    // 初始化邻接矩阵
    for (int i = 0; i < G.n; i++)
        for (int j = 0; j < G.n; j++)
            G.adj[i][j] = 0;
    // 输入边
    int u, v;
    while (scanf("%d %d", &u, &v) && !(u == -1 && v == -1)) {
        G.adj[u][v] = 1; // 有向图
    }
    // 统计入度和出度
    int in[MAXV] = {0};
    int out[MAXV] = {0};
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            if (G.adj[i][j]) {
                out[i]++;
                in[j]++;
            }
        }
    }
    // 输出所有出度 > 入度 的顶点
    int count = 0;
    for (int i = 0; i < G.n; i++) {
        if (out[i] > in[i]) {
            printf("%c ", G.vertex[i]);
            count++;
        }
    }
    if (count == 0) {
        printf("NONE\n");
        printf("0\n"); 
    } else {
        printf("\n%d\n", count);
    }

    return 0;
}

