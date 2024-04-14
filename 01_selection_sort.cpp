#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) 
  {
    int minIndex = i;
    for (int com = i + 1; com < size; com++) 
    {
      if (arr[com] < arr[minIndex])
      {
        minIndex = com;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
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

  selectionSort(array, size);
  cout << "Sorted array: ";
  printArray(array, size);
  return 0;
}
