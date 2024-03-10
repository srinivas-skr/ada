#include<iostream>
using namespace std;
int n, a[20][20], s[20], d[20], v;

void dijkstra(){
    int u;
    // Initialize distances and visited array
    for(int i = 1; i<=n; i++){
        d[i] = a[v][i];
        s[i] = 0;
    }
    d[v] = 0;
    s[v] = 1;
    
    // Dijkstra's algorithm
    for(int k = 2; k<=n; k++){
        int min = 99;
        // Find the vertex with the minimum distance from the source among the unvisited vertices
        for(int i = 1; i<=n; i++)
            if(s[i]==0 && d[i] < min){
                min = d[i];
                u = i;
            }
        
        s[u] = 1;
        // Update distances for vertices adjacent to the selected vertex
        for(int i = 1; i <= n; i++)
            if(s[i] == 0){
                if(d[i] > d[u] + a[u][i])
                    d[i] = d[u] + a[u][i];
            }
    }
    cout<<"The shortest path from "<<v<<" is "<<endl;
    for(int i = 1; i<=n; i++)
        cout<<v<<"-->"<<i<<"="<<d[i]<<endl;
}

int main(){
    cout<<"Vertices: ";
    cin>>n;
    
    cout<<"\nCost matrix: ";
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin>>a[i][j];
    
    cout<<"\nSource vertex: ";
    cin>>v;
    dijkstra();
    return 0;
}
