#include <iostream>
using namespace std;

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

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int array[size];
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }

  cout << "Unsorted array: ";
  printArray(array, size);

  selectionSort(array, size);
  cout << "Sorted array: ";
  printArray(array, size);

  return 0;
}
