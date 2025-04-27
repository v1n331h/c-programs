#include <stdio.h>

#define NUM_OFFICERS 7

// Depth First Search (DFS) using recursion
void dfs(int adj[NUM_OFFICERS][NUM_OFFICERS], int visited[], int start) {
    printf("%d ", start + 1);
    visited[start] = 1;
    for (int i = 0; i < NUM_OFFICERS; i++) {
        if (adj[start][i] && !visited[i]) {
            dfs(adj, visited, i);
        }
    }
}

// Breadth First Search (BFS) using a queue
void bfs(int adj[NUM_OFFICERS][NUM_OFFICERS], int start) {
    int visited[NUM_OFFICERS] = {0};
    int queue[NUM_OFFICERS], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current + 1);
        for (int i = 0; i < NUM_OFFICERS; i++) {
            if (adj[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    // Language fluency matrix
    int languages[NUM_OFFICERS][4] = {
        {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1},
        {0, 1, 0, 1}, {1, 1, 0, 0}, {1, 0, 1, 0}, {0, 1, 0, 0}
    };

    // Create adjacency matrix
    int adj[NUM_OFFICERS][NUM_OFFICERS] = {0};
    for (int i = 0; i < NUM_OFFICERS; i++) {
        for (int j = 0; j < NUM_OFFICERS; j++) {
            if (i != j) {
                for (int k = 0; k < 4; k++) {
                    if (languages[i][k] && languages[j][k]) {
                        adj[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    // Input starting officer
    int start;
    printf("Enter the starting officer (1 to 7): ");
    scanf("%d", &start);
    start--;

    // Perform DFS
    printf("Reachable officers using DFS: ");
    int visited[NUM_OFFICERS] = {0};
    dfs(adj, visited, start);
    printf("\n");

    // Perform BFS
    printf("Reachable officers using BFS: ");
    bfs(adj, start);
    printf("\n");

    return 0;
}