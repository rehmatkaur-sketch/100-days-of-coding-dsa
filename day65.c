#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

// DFS cycle detection
int dfs(int node, int parent, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int neigh = temp->data;

        if (!visited[neigh]) {
            if (dfs(neigh, node, adj, visited))
                return 1;
        }
        else if (neigh != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}