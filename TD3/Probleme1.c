#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int id;
    struct Node *left, *right;
} Node;



Node* newNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->left = node->right = NULL;
    return node;
}


Node* insert(Node* root, int id) {
    if (root == NULL)
        return newNode(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}


int search(Node* root, int id) {
    if (root == NULL)
        return 0;
    if (root->id == id)
        return 1;
    if (id < root->id)
        return search(root->left, id);
    else
        return search(root->right, id);
}



void solveInfiniteLibrary() {
    int N;
    scanf("%d", &N);

    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        root = insert(root, id);
    }

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int x;
        scanf("%d", &x);
        if (search(root, x))
            printf("YES\n");
        else
            printf("NO\n");
    }

}


void main() {
    solveInfiniteLibrary();
}
