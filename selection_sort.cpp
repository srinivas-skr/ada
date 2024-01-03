#include <iostream>
using namespace std;
// Time Complexity: O(n^2) - Quadratic time complexity due to nested loops
// Space Complexity: O(1) - Constant space, as the sorting is done in-place
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

// Function to print the elements of an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // Initializing array with values
  int array[] = {12, 8, 5, 16, 2};

  // Determining the size of the array
  int size = sizeof(array) / sizeof(array[0]);

  cout << "Unsorted array: ";
  printArray(array, size);

  // Sorting the array using Selection Sort
  selectionSort(array, size);

  cout << "Sorted array: ";
  printArray(array, size);

  return 0;
}
