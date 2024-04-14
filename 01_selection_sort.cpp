#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) 
  {
    int min = i;
    for (int com = i + 1; com < size; com++) 
    {
      if (arr[com] < arr[min])
      {
        min = com;
      }
    }
    swap(arr[i], arr[min]);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
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
