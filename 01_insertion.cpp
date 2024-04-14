#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int sh = i - 1;

    while (sh >= 0 && arr[sh] > key) {
      arr[sh + 1] = arr[sh];
      sh--;
    }
    arr[sh + 1] = key;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
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
