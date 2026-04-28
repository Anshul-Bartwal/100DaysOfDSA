#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// -------- Graph --------
int adj[MAX][MAX];
int n;

// -------- Min Heap Node --------
struct HeapNode {
    int v;
    int dist;
};

// -------- Min Heap --------
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// swap
void swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

// heapify up
void heapifyUp(struct MinHeap *h, int i) {
    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// heapify down
void heapifyDown(struct MinHeap *h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// insert into heap
void push(struct MinHeap *h, int v, int dist) {
    h->heap[h->size].v = v;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// extract min
struct HeapNode pop(struct MinHeap *h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return root;
}

// -------- Dijkstra --------
void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        struct HeapNode node = pop(&h);
        int u = node.v;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(&h, v, dist[v]);
                }
            }
        }
    }

    // print result
    for (int i = 0; i < n; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

// -------- Main --------
int main() {
    int src;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    scanf("%d", &src);

    dijkstra(src);

    return 0;
}