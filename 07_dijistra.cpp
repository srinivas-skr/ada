#include<iostream>
using namespace std;
int n, a[20][20], s[20], d[20], v;

void dijkstra() {
    int u;
    for(int i = 1; i <= n; i++) {         // Initialize distances and visited array
        d[i] = a[v][i];                // Initialize distance from source to vertex i
        s[i] = 0;                         // Mark vertex i as unvisited
    }
    d[v] = 0;                       // Distance from source to itself is 0
    s[v] = 1;                      // Mark the source vertex as visited
    for(int k = 2; k <= n; k++) {
        int min = 99;                  // Initialize minimum distance to a large value

        for(int i = 1; i <= n; i++) // Find the vertex with the minimum distance from the source among the unvisited vertices
            if(s[i] == 0 && d[i] < min) {
                min = d[i];  // Update minimum distance
                u = i;       // Update vertex u to the one with minimum distance
            }
        
        s[u] = 1;   // Mark vertex u as visited
        for(int i = 1; i <= n; i++)  // Update distances for vertices adjacent to the selected vertex
            if(s[i] == 0)
                if(d[i] > d[u] + a[u][i])
                    d[i] = d[u] + a[u][i];
    }
    
    cout << "The shortest path from " << v << " is " << endl;   // Output shortest paths
    for(int i = 1; i <= n; i++)
        cout << v << "-->" << i << "=" << d[i] << endl;
}

int main() {
    cout << "Vertices: ";
    cin >> n;

    cout << "\nCost matrix: ";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    
    cout << "\nSource vertex: ";
    cin >> v;
    // Perform Dijkstra's algorithm
    dijkstra();
    return 0;
}

/* OUTPUT
Vertices: 4
Cost matrix:
0 10 3 999
10 0 1 2
3 1 0 8
999 2 8 0
Source vertex: 1 */
