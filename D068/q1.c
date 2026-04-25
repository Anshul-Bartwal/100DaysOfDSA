#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], indeg[MAX], queue[MAX];
int n;

void kahn() {
    int front = 0, rear = 0;

    // compute indegree
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j]) indeg[j]++;

    // push all nodes with indegree 0
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            queue[rear++] = i;

    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                indeg[i]--;
                if (indeg[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != n)
        printf("\nCycle exists");
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    kahn();
    return 0;
}