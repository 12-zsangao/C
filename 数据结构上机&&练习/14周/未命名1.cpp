#include <stdio.h>
#include <string.h>

#define MAXV 100

typedef struct {
    int numVertices, numEdges;             // 顶点数和边数
    char VerticesList[MAXV];               // 顶点名
    int Edge[MAXV][MAXV];                  // 邻接矩阵
} MGraph;

int uniquely(MGraph G) {
    int indegree[MAXV] = {0};
    int i, j;

    // 计算每个顶点的入度
    for (i = 0; i < G.numVertices; i++) {
        for (j = 0; j < G.numVertices; j++) {
            if (G.Edge[i][j])
                indegree[j]++;
        }
    }

    int count = 0;

    for (int k = 0; k < G.numVertices; k++) {
        int zeroCount = 0;
        int zeroIndex = -1;

        for (i = 0; i < G.numVertices; i++) {
            if (indegree[i] == 0) {
                zeroCount++;
                zeroIndex = i;
            }
        }

        if (zeroCount == 0)
            return 0;  // 有环，不是拓扑图
        if (zeroCount > 1)
            return 0;  // 入度为0的点不唯一，拓扑序不唯一

        indegree[zeroIndex] = -1;  // 删除该顶点
        count++;

        for (j = 0; j < G.numVertices; j++) {
            if (G.Edge[zeroIndex][j])
                indegree[j]--;
        }
    }

    return (count == G.numVertices); // 是否所有点都拓扑排序过
}

int main() {
    MGraph G;
    char ch;
    int i, j;

    // 输入顶点
    int len = 0;
    while ((ch = getchar()) != '#') {
        if (ch != '\n' && ch != ' ') {
            G.VerticesList[len++] = ch;
        }
    }
    G.numVertices = len;

    // 初始化邻接矩阵
    for (i = 0; i < G.numVertices; i++) {
        for (j = 0; j < G.numVertices; j++) {
            G.Edge[i][j] = 0;
        }
    }

    // 输入边
    scanf("%d", &G.numEdges);
    char u, v;
    for (i = 0; i < G.numEdges; i++) {
        scanf(" %c %c", &u, &v);
        int from = -1, to = -1;
        for (j = 0; j < G.numVertices; j++) {
            if (G.VerticesList[j] == u) from = j;
            if (G.VerticesList[j] == v) to = j;
        }
        if (from != -1 && to != -1)
            G.Edge[from][to] = 1;
    }

    if (uniquely(G))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

