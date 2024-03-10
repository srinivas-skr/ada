#include<iostream>
using namespace std;

int main() {
    int n, i, j, a[10][10], d[10], s[10], v, k, min, u;

    cout << "No. of vertices: ";
    cin >> n;
    
    cout << "\nCost matrix: ";
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];

    cout << "\nSource vertex: ";
    cin >> v;

    for(i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = a[v][i];
    }

    d[v] = 0;
    s[v] = 1;

    for(k = 2; k <= n; k++) {
        min = 99;
        for(i = 1; i <= n; i++) {
            if(s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        s[u] = 1;

        for(i = 1; i <= n; i++) {
            if(s[i] == 0) {
                if(d[i] > (d[u] + a[u][i]))
                    d[i] = d[u] + a[u][i];
            }
        }
    }

    cout << "\nShortest distance from " << v << " is " << endl;
    for(i = 1; i <= n; i++) {
        if (i != v)
       cout << v << "--->" << i << "=" << d[i] << endl;
    }
    return 0;
}
