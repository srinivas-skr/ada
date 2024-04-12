#include<iostream>
using namespace std;
int visited[20],a[20][20],n,i,v;

void dfs(int v) {
    visited[v] = 1;
    for(i=1; i<=n; i++) {
        if(a[v][i] && !visited[i]) {
            cout<<v<<"->"<<i<<endl;
            dfs(i);
        }
    }  
}

int main()
{
 int count = 0;
 cout<<"Enter no of vertices: ";
 cin>>n;
 for(int i=1; i<=n; i++) {
    visited[i] = 0;
    for(int j=1; j<=n; j++) {
        a[i][j] = 0;
    }
 }
    
 cout<<"Enter adjacency matrix: ";
 for(int i=1;i<=n;i++) {
    for(int j=1; j<=n; j++) {
        cin>>a[i][j];
    }
 }
    
 cout<<"Enter starting vertex: ";
 cin>>v;
 dfs(v);
 
 for(int i=1; i<=n; i++) {
    if(visited[i]) {
        count++;
    }
 }
    
 if (count == n) {
    cout<<"Graph is connected. ";
 }
 else {
    cout<<"Graph is disconnected. ";
 }
 return 0;
}
