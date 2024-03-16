#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
  for (int j = 1; j < n; j++) {
    int key = arr[j];
    int i = j - 1;

    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i--;
    }
    arr[i + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int size;
  cout << "Enter the size of the array: "; // Modified to prompt user for input
  cin >> size;

  int array[size];

  cout << "Enter " << size << " elements of the array: "; 
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
  
  insertionSort(array, size);
  cout << "Sorted array: ";
  printArray(array, size);
  return 0;
}
