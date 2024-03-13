#include <iostream>
using namespace std;

void warshall(int a[20][20], int n);  // Function declaration

int main() {
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    int a[20][20];  // Array declaration for adjacency matrix
    cout << "Enter the adjacency matrix (0/1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << endl;
    warshall(a, n); // Call the function to compute and print the transitive closure
    return 0;
}

// Function definition
void warshall(int a[20][20], int n) {
    // Applying Warshall's algorithm
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);

    // Printing the transitive closure matrix
    cout << "\nTransitive closure matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}
