#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int size = 5;
  int array[] = {12, 8, 5, 16, 2};

  cout << "Unsorted array: ";
  printArray(array, size);

  insertionSort(array, size);

  cout << "Sorted array: ";
  printArray(array, size);
  return 0;
}
