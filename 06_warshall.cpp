#include <iostream>
using namespace std;

void warshall(int a[][20], int n)      // Warshall's algorithm to compute transitive closure  
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);

    cout << "\nTransitive closure matrix: " << endl;    // Printing the transitive closure matrix
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int a[20][20];
    cout << "Enter the adjacency matrix (0/1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    warshall(a, n);         // Call the function to compute and print the transitive closure
    return 0;
}
