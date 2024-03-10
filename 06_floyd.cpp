#include <iostream>
using namespace std;

const int INF = 999;

int main() {
    int distances[10][10], n;

    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the distances between cities (use 999 for infinity and 0 for loop):\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> distances[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);

    cout << "\nShortest paths between cities:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << distances[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}

/*output 
Enter the number of cities: 4
Enter the distances between cities (use 999 for infinity):
0 3 6 15
3 0 2 999
6 2 0 1
15 999 1 0
*/
