#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

class Horspool {
public:
    Horspool(const string& pattern) : pattern(pattern), table(256, pattern.size()) {
        for (int i = 0; i < pattern.size() - 1; ++i)
            table[pattern[i]] = pattern.size() - 1 - i;
    }

    int search(const string& text) {
        int m = pattern.size();
        int n = text.size();
        int i = m - 1;

        while (i < n) {
            int k = 0;
            while (k < m && (pattern[m - 1 - k] == text[i - k]))
                k++;

            if (k == m)
                return i - m + 1;
            else
                i += max(1, m - 1 - table[text[i]]);
        }

        return -1;
    }

private:
    string pattern;
    vector<int> table;
};

int main() {
    string text = "This is a sample text to search for a pattern.";
    string pattern = "This";

    Horspool horspool(pattern);

    auto start = chrono::high_resolution_clock::now();
    int result = horspool.search(text);
    auto end = chrono::high_resolution_clock::now();

    if (result == -1)
        cout << "\nPattern not found\n";
    else
        cout << "Pattern found at " << result + 1 << " position\n";

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Time of Horsepool's Algorithm: " << duration << " microseconds\n";

    return 0;
}