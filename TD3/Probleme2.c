#include <stdio.h>
#include <stdlib.h>

int tall = 100000;

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[100000];
int visited[100000];
int dist[100000];


void add_edge(int u, int v) {
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->v = v;
    node1->next = adj[u];
    adj[u] = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->v = u;
    node2->next = adj[v];
    adj[v] = node2;
}

void DFS(int u) {
    visited[u] = 1;
    for (Node* p = adj[u]; p != NULL; p = p->next) {
        if (!visited[p->v])
            DFS(p->v);
    }
}


int BFS(int start, int target, int n) {
    for (int i = 1; i <= n; i++)
        dist[i] = -1;

    int queue[tall];
    int front = 0, rear = 0;

    queue[rear++] = start;
    dist[start] = 0;

    while (front < rear) {
        int u = queue[front++];
        for (Node* p = adj[u]; p != NULL; p = p->next) {
            if (dist[p->v] == -1) {
                dist[p->v] = dist[u] + 1;
                queue[rear++] = p->v;
                if (p->v == target)
                    return dist[p->v];
            }
        }
    }
    return -1;
}

void main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    int A, B;
    scanf("%d %d", &A, &B);

    // 1)
    int kingdoms = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i);
            kingdoms++;
        }
    }


    // 2)
    int shortest_path = BFS(A, B, N);

    printf("%d\n", kingdoms);
    printf("%d\n", shortest_path);

}
