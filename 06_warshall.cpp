#include<iostream>
using namespace std;

void warshall(int a[][20], int n){
    // Warshall's algorithm to compute transitive closure
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
    
    // Printing the transitive closure matrix
    cout<<"\nTransitive closure matrix: "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}

int main(){
    int n = 4; // Number of vertices
    int a[20][20] = {
        {0, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    }; // Hard-coded adjacency matrix

    // Call the function to compute and print the transitive closure
    warshall(a, n);
    return 0;
}
