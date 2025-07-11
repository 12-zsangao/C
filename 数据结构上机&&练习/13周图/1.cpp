#include <stdio.h>

#define MAXV 100
typedef struct {
    char vertex[MAXV];
    int adj[MAXV][MAXV];
    int n;
} MGraph;

int visited[MAXV];

// ���� visited ����Ϊ 0
void resetVisited(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

int DFS(MGraph* G, int start, int end) {
    if (start == end) return 1;
    visited[start] = 1;
    for (int i = 0; i < G->n; i++) {
        if (G->adj[start][i] && !visited[i]) {
            if (DFS(G, i, end)) return 1;
        }
    }
    return 0;
}

int main() {
    MGraph G;
    G.n = 0;
    char ch;
    while ((ch = getchar()) != '!') {
        G.vertex[G.n++] = ch;
    }
    for (int i = 0; i < G.n; i++)
        for (int j = 0; j < G.n; j++)
            G.adj[i][j] = 0;
    int u, v;
    while (scanf("%d %d", &u, &v) && !(u == -1 && v == -1)) {
        G.adj[u][v] = 1; // ����ͼ
    }

    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            printf("%d ", G.adj[i][j]);
        }
        printf("\n");
    }

    char from, to;
    scanf(" %c%c", &from, &to);

    // ���ұ��
    int start = -1, end = -1;
    for (int i = 0; i < G.n; i++) {
        if (G.vertex[i] == from) start = i;
        if (G.vertex[i] == to) end = i;
    }

    // ·���ж�
    resetVisited(G.n);
    if (DFS(&G, start, end))
        printf("T\n");
    else
        printf("F\n");

    return 0;
}

