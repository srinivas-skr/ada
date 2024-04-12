#include<iostream>
using namespace std;

void warshall(int a[][20], int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
    
    cout<<"\nPath matrix: "<<endl;
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout<<a[i][j]<<"\t";
            cout<<endl;
    }
}

int main(){
    int n, a[20][20];
    cout<<"No. of vertices: ";
    cin>>n;
    
    cout<<"\adjacency matrix: ";
    for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>a[i][j];
    
    warshall(a, n);
    return 0;
}
