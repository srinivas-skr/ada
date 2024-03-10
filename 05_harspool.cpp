#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int horspool_search(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (n < m) return -1;

unordered_map<char, int> bad_char_shift;
    for (int i = 0; i < m - 1; ++i)
        bad_char_shift[pattern[i]] = m - 1 - i;

    for (int i = m - 1; i < n;) {
        int j = m - 1;
        while (j >= 0 && text[i] == pattern[j]) {
            --i;
            --j;
        }
        if (j < 0) return i + 1;
        i += bad_char_shift[text[i]] > 0 ? bad_char_shift[text[i]] : m;
    }
    return -1;
}

int main() {
    string text = "This is a sample text to search for a pattern.";
    string pattern = "sample";
    int result = horspool_search(text, pattern);
    if (result != -1)
        cout << "Pattern found at position " << result << endl;
    else
        cout << "Pattern not found in the text." << endl;
    return 0;
}
