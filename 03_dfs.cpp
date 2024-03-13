#include<iostream>
using namespace std;

int visited[20], a[20][20], n, i, v;

void dfs(int v) {
    visited[v] = 1;
    cout << v << " ";
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int count = 0;
    n = 4; // Number of vertices
    // Define the adjacency matrix for the predefined graph
    int adjMatrix[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    // Copy the predefined adjacency matrix to the actual adjacency matrix
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            a[i][j] = adjMatrix[i - 1][j - 1];
        }
    }
    cout << "DFS Traversal: ";
    dfs(1); // Start DFS from vertex 1

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            count++;
        }
    }
    
    if (count == n) {
        cout << "\nGraph is connected. ";
    } else {
        cout << "\nGraph is disconnected. ";
    }
    return 0;
}
