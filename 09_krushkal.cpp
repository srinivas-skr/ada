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

int checkCycle(int x, int y) {
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
    
cout<<min;
    
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

/*output
No. Of vertices: 5
Enter cost matrix:
99   1   7  10  5
 1  99   3  99  99
 7   3  99   4  99
10  99   4  99   2
 5  99  99   2  99
 
01--->2=1
4--->5=2
2--->3=3
3--->4=4
Total cost: 10 
 */
