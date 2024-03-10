#include <iostream>
#include <climits>
using namespace std;

const int MAX_VERTICES = 100;

int minCost, cost[MAX_VERTICES][MAX_VERTICES], parent[MAX_VERTICES], n;

void findMin();
int find(int vertex);
void unionVertices(int x, int y);

int main() {
    int count = 0, totalCost = 0, flag = 0;
    cout << "Enter the number of towns: ";
    cin >> n;
    cout << "Enter the cost matrix" << endl;
    cout << "Enter 999 for No edges and self-loops" << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < MAX_VERTICES; i++) // Initialize parent array
        parent[i] = 0;

    while (count != n - 1 && minCost != 999) {
        findMin();
        flag = find(x) != find(y);

        if (flag) {
            cout << x << " -----> " << y << " == " << cost[x][y] << endl;
            totalCost += cost[x][y];
            ++count;
            unionVertices(x, y);
        }
        cost[x][y] = cost[y][x] = 999;
    }
    cout << "The total cost of the least expensive tree = " << totalCost << endl;
    return 0;
}

void findMin() {
    minCost = INT_MAX;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cost[i][j] < minCost && i != j) {
                minCost = cost[i][j];
                x = i;
                y = j;
            }
}

int find(int vertex) {
    while (parent[vertex] != 0)
        vertex = parent[vertex];
    return vertex;
}

void unionVertices(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);
    parent[parentX] = parentY;
}



#Enter the number of towns: 4
Enter the cost matrix
Enter 999 for No edges and self-loops
0 1 3 999
1 0 2 4
3 2 0 5
999 4 5 0
