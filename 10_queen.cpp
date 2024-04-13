#include<iostream>
using namespace std;
int count = 0, x[100];

int place (int r, int c){        // Function to check if it's possible to place a queen at a specific position
    for (int j = 1; j < r; j++)  // Iterate over all the previously placed queens
        if ((x[j] == c) || (abs(x[j] - c) == abs(j - r)))     // Check for conflicts in the same column or diagonal
            return 0;   // Conflict found
    return 1;    // No conflict found
}

void nQueen(int r, int n) {     // Recursive function to find solutions for the N-Queens problem
   
    for (int c = 1; c <= n; c++)  {
        if ( place (r, c) ) {      // Check if it's possible to place a queen at the current position
            x[r] = c;
            
            if (r == n) {
                count++;
                for (int j = 1; j <= n; j++) {
                    for (int p = 1; p <= n; p++) {
                        if (x[j] == p)
                            cout << "Q"; // Queen placed at this position
                        else
                            cout << "0"; // Empty position
                    }
                    cout << endl;
                }
                cout << endl;
            }
            
            else {
                nQueen(r + 1, n);    // Recursively explore the next row
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    
    nQueen(1, n);

    if (count == 0)                    // Print the number of solutions found
        cout << "\nNo solution";
    else
        cout << "Number of solutions: " << count;
    return 0;
}
