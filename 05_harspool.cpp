#include <iostream>
#include <string>

using namespace std;

void ShiftTable(const string& P, int m, int Table[]) {
    int size = 256; // Assuming ASCII characters
    for (int i = 0; i < size; ++i) {
        Table[i] = m;
    }
    for (int j = 0; j < m - 1; ++j) {
        Table[P[j]] = m - 1 - j;
    }
}

int HorspoolMatching(const string& P, const string& T) {
    int m = P.size();
    int n = T.size();
    int Table[256]; // Assuming ASCII characters
    ShiftTable(P, m, Table);
    int i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k <= m - 1 && P[m - 1 - k] == T[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1; // Match found
        } else {
            i += Table[T[i]];
        }
    }
    return -1; // No match found
}

int main() {
    string pattern = "algorithm";
    string text = "Implementing Horspool's algorithm for string matching";
    int index = HorspoolMatching(pattern, text);
    if (index != -1) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }
    return 0;
}
