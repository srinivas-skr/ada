#include<iostream>
using namespace std;
int n, c[20][20], i, j, visited[20];

void prim() {
    int min, a, b, k, count = 0, cost = 0;
    min = 99;
    visited[1] = 1;

    while (count < n - 1) {
        min = 99;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (visited[i] && !visited[j] && min > c[i][j]) {
                    min = c[i][j];
                    a = i;
                    b = j;
                }

        cout << a << " ---> " << b << " = " << c[a][b] << endl;
        cost = cost + c[a][b];
        visited[b] = 1;
        count++;
    }
    cout << "Total cost of MST is " << cost;
}

int main() {
    cout << "How many vertices? \n";
    cin >> n;
    
    cout << "Enter cost matrix: \n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cin >> c[i][j];
        visited[i] = 0;
    }
    prim();
}

/* output
how many vertices? 4
Enter cost matrix: 
0 1 2 3
1 0 4 5
2 4 0 6
3 5 6 0
*/
