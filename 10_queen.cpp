#include <iostream>
using namespace std;

int count = 0, x[100];

bool canPlace(int k, int i) {
    for (int j = 1; j < k; j++)
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    return true;
}

void nQueen(int k, int n) {
    for (int i = 1; i <= n; i++)
        if (canPlace(k, i)) {
            x[k] = i;
            if (k == n) {
                count++;
                for (int j = 1; j <= n; j++, cout << endl)
                    for (int p = 1; p <= n; p++)
                        cout << (x[j] == p ? "Q" : "0");
            } else
                nQueen(k + 1, n);
        }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    nQueen(1, n);
    cout << (count == 0 ? "\nNo solution" : "Number of solutions: " + to_string(count));
    return 0;
}
