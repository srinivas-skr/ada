#include<iostream>
using namespace std;

int cost[100][100], parent[20], x, y, i, j, n;

void findMin(){
    int min = 99;
    for(i = 1; i<=n; i++)
        for(j = 1; j<=n; j++)
            if(cost[i][j] < min){
                min = cost[i][j];
                x = i;
                y = j;
            }
}

int checkCycle(int x, int y){
    if((parent[x]==parent[y]) && (parent[x]!=0))
        return 0;
    else if(parent[x]==0 && parent[y]==0)
        parent[x] = parent[y] = x;
    else if(parent[x]==0)
        parent[x] = parent[y];
    else if(parent[x]!=parent[y])
        parent[y] = parent[x];
    return 1;
}


int main(){
    int min;
    int count = 0, tot = 0, flag = 0;
    cout<<"No. Of vertices: ";
    cin>>n;
    cout<<"\nEnter cost matrix: ";
    for(i = 1; i<=n; i++)
        for(j = 1; j<=n; j++){
            cin>>cost[i][j];
            parent[j] = 0;
        }
            
    while (count != n-1 && min != 99){
        findMin();
        flag = checkCycle(x, y);
        if(flag==1){
            cout<<x<<"--->"<<y<<"="<<cost[x][y]<<endl;
            count++;
            tot = tot + cost[x][y];
        }
        cost[x][y] = cost[y][x] = 99;
    } 
    
    cout<<"Total cost: "<<tot;
}

/* output
Enter the number of towns: 4
Enter the cost matrix
Enter 999 for No edges and self-loops
0 1 3 999
1 0 2 4
3 2 0 5
999 4 5 0 */
