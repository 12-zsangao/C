#include <stdio.h>

#define MAXN 1005
int graph[MAXN][MAXN];
int indegree[MAXN];
int bonus[MAXN];
int queue[MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // ��ʼ��
    int i, j;
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        bonus[i] = 100;
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    // ��ͼ
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        // a �Ľ������ b����� b -> a �ı�
        if (graph[b][a] == 0) { 
            graph[b][a] = 1;
            indegree[a]++;
        }
    }

    int front = 0, rear = 0;
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;
    while (front < rear) {
        int u = queue[front++];
        count++;

        for (i = 0; i < n; i++) {
            if (graph[u][i]) {
                if (bonus[i] < bonus[u] + 1)
                    bonus[i] = bonus[u] + 1;

                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != n) {
        // �л�
        printf("POOR!\n");
    } else {
        // ͳ���ܽ���
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += bonus[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}

