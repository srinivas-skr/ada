#include <iostream>
using namespace std;

const int INF = 999; // Constant representing infinity

int main() {
    int distances[10][10], n;

    cout << "Enter the number of cities: \n";
    cin >> n;

    cout << "Enter the distances between cities (use 999 for infinity and 0 for loop):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> distances[i][j];

    // Floyd-Warshall algorithm to find the shortest paths between cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Update the distance if the new path through city k is shorter
                if (distances[i][j] > distances[i][k] + distances[k][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    cout << "Shortest paths between cities:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << distances[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}


/* output
Enter the number of cities: 
4

Enter the distances between cities (use 999 for infinity and 0 for loop):
0 2 999 10
999 0 3 999
999 999 0 7
999 999 999 0

Shortest paths between cities:
0       2       5       10
999     0       3       10
999     999     0       7
999     999     999     0

*/
