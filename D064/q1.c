#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Queue
int queue[MAX];
int front = 0, rear = 0;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Enqueue
void enqueue(int x) {
    queue[rear++] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// BFS function
void bfs(int start) {
    visited[start] = 1;
    enqueue(start);

    while (front < rear) {
        int node = dequeue();
        printf("%d ", node);

        struct Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    scanf("%d", &start);

    bfs(start);

    return 0;
}