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
  int array[100]; // Assuming maximum size of the array is 100
  int size;
  
  cout << "Enter the size of the array: "; // Modified to prompt user for input
  cin >> size;

  cout << "Enter " << size << " elements of the array: "; 
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
  
  insertionSort(array, size);
  cout << "Sorted array: ";
  printArray(array, size);
  return 0;
}
