#include <stdio.h>
#define MAXV 100
typedef struct {
    char vertex[MAXV];
    int adj[MAXV][MAXV];
    int n;
} MGraph;

int visited[MAXV];

// ��ʼ��
void resetVisited(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

// DFS �������ͼ�Ƿ��л�
int hasCycle(MGraph* G, int u, int parent) {
    visited[u] = 1;
    for (int v = 0; v < G->n; v++) {
        if (G->adj[u][v]) {
            if (!visited[v]) {
                if (!hasCycle(G, v, u)) return 0;
            } else if (v != parent) {
                return 0; // �лر�
            }
        }
    }
    return 1;
}

int main() {
    MGraph G;
    G.n = 0;
    char ch;
    // ���붥��
    while ((ch = getchar()) != '!') {
        G.vertex[G.n++] = ch;
    }
    // ��ʼ���ڽӾ���
    for (int i = 0; i < G.n; i++)
        for (int j = 0; j < G.n; j++)
            G.adj[i][j] = 0;
    // ����ߣ�����ͼ��
    int u, v;
    int edgeCount = 0;
    while (scanf("%d %d", &u, &v) && !(u == -1 && v == -1)) {
        G.adj[u][v] = 1;
        G.adj[v][u] = 1;
        edgeCount++;
    }
    // ����Ƿ���
    resetVisited(G.n);
    if (!hasCycle(&G, 0, -1)) {
        printf("NO\n");
        return 0;
    }
	//�Ƿ�������ж���
    for (int i = 0; i < G.n; i++) {	
        if (!visited[i]) {
            printf("NO\n");
            return 0;
        }
    }

    if (edgeCount != G.n - 1) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}

