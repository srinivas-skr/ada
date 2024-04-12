#include<iostream>
using namespace std;

void warshall(int distance[][20], int n){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                distance[i][j] = distance[i][j] || (distance[i][k] && distance[k][j]);
    
    cout<<"\nPath matrix: "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<distance[i][j]<<"\t";
        cout<<endl;
    }
}

int main(){
    int n, distance[20][20];
    cout<<"No. of vertices: ";
    cin>>n;
    
    cout<<"\nAdjacency matrix: ";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>distance[i][j];
    
    warshall(distance, n);
    return 0;
}
