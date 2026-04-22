#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX], recStack[MAX];
int n;

int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;   // cycle found
        }
    }

    recStack[v] = 0;  // backtrack
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (hasCycle())
        printf("YES");
    else
        printf("NO");

    return 0;
}