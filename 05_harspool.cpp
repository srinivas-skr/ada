#include <iostream>  // Include the input/output stream library
#include <string>    // Include the string library for string manipulation

using namespace std;  // Use the standard namespace

const int Size = 256;  // Define a constant Size for the size of the shift table (assuming ASCII characters)

// Function to create the shift table for the pattern

void ShiftTable(const string& P, int l, int Table[]) {
    for (int i = 0; i < Size; i++) {
        Table[i] = l;                     // Initialize all entries of the table with the length of the pattern
    }
    for (int j = 0; j < l - 1; j++) {
        Table[P[j]] = l - 1 - j;              // Calculate and store the shift value for each character in the pattern
    }
}

// Function to perform Horspool string matching algorithm
int HorspoolMatching(const string& P, const string& T) {
    int l = P.size();  // Length of the pattern
    int n = T.size();  // Length of the text
    int Table[Size];  // Shift table for the pattern
    ShiftTable(P, l, Table);  // Create the shift table
    int i = l - 1;                               // Start comparing from the end of the pattern
    while (i <= n - 1) {                              // Iterate over the text until the end
        int k = 0;                               // Initialize the offset within the pattern
        while (k <= l - 1 && P[l - 1 - k] == T[i - k]) {                    // Compare characters from the end of the pattern
            k++;                                              // Increment the offset if characters match
        }
        if (k == l) {                // If entire pattern is matched
            return i - l + 1;              // Return the index where the match starts
        } else {
            i += Table[T[i]];            // Shift the pattern based on the shift value from the table
        }
    }
    return -1;  // If no match is found, return -1
}

int main() {
    string pattern, text;             // Declare variables to store the pattern and text strings
    cout << "Enter the text: ";         // Prompt the user to enter the text
    getline(cin, text);                        // Read the text input from the user
        cout << "Enter the pattern: ";   // Prompt the user to enter the pattern
    getline(cin, pattern);                // Read the pattern input from the user
    
    
    int index = HorspoolMatching(pattern, text);        // Call the HorspoolMatching function to find the pattern in the text
    if (index == -1) {                                  // Check if no match is found
        cout << "Pattern not found in the text." << endl;  // Print message if pattern is not found
    } else {
        cout << "Pattern found at index: " << index << endl;  // Print the index where the pattern is found
    }
    return 0;  // Return 0 to indicate successful execution
}
