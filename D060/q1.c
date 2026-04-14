#include <stdio.h>
#include <stdlib.h>

// Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[100];

    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n)
            nodes[i]->left = nodes[left];
        if (right < n)
            nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check completeness
int isComplete(struct Node* root, int index, int total) {
    if (root == NULL)
        return 1;

    if (index >= total)
        return 0;

    return isComplete(root->left, 2*index + 1, total) &&
           isComplete(root->right, 2*index + 2, total);
}

// Check heap property
int isHeap(struct Node* root) {
    if (root == NULL)
        return 1;

    if (root->left && root->data > root->left->data)
        return 0;

    if (root->right && root->data > root->right->data)
        return 0;

    return isHeap(root->left) && isHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int total = countNodes(root);

    if (isComplete(root, 0, total) && isHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}