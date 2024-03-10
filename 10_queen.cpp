#include<iostream>
using namespace std;
int count = 0, x[100];

int place(int k,int i){     //checking if we can place kth queen in ith position
    for(int j = 1; j<k; j++)
        if((x[j] == i) || (abs(x[j]-i) == abs(j-k)))
            return 0;
    return 1;
}

void nQueen(int k, int n){
    
    for(int i = 1; i<=n; i++)
        if(place(k, i)){
            x[k] = i;
            if(k == n){
                count++;
                
                for(int j = 1; j<=n; j++){
                    for(int p = 1; p<=n; p++)
                        if(x[j] == p)
                            cout<<"Q";
                        else
                            cout<<"0";
                    cout<<endl;
                }
            }
            else
                nQueen(k+1, n);
        }
        cout<<endl;
}

int main(){
    int n;
    cout<<"Enter number of queens: ";
    cin>>n;
    nQueen(1, n);
    if(count == 0)
        cout<<"\nNo solution";
    else
        cout<<"Number of solutions: "<<count;
}
