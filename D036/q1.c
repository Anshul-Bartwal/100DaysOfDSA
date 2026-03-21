#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value, int size) {
    if ((rear + 1) % size == front) {
        // Queue full (won't happen here usually)
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
}

// Dequeue
void dequeue(int size) {
    if (front == -1) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

// Display
void display(int size) {
    if (front == -1) return;

    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);

    // Enqueue all elements
    for (int i = 0; i < n; i++) {
        enqueue(arr[i], n);
    }

    // Dequeue m times
    for (int i = 0; i < m; i++) {
        dequeue(n);
    }

    // Enqueue first m elements again (circular behavior)
    for (int i = 0; i < m; i++) {
        enqueue(arr[i], n);
    }

    // Display final queue
    display(n);

    return 0;
}