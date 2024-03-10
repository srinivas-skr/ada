#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int n)
{
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

// Function to print the elements of an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // Define the array with values directly
  int size = 5;
  int array[] = {12, 8, 5, 16, 2};

  cout << "Unsorted array: ";
  printArray(array, size);
  // Measure the time taken by the Insertion Sort algorithm
  auto start_time = high_resolution_clock::now();
  insertionSort(array, size);

  auto stop_time = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop_time - start_time);

  cout << "Sorted array: ";
  printArray(array, size);
  cout << "Time taken by Insertion Sort: " << duration.count() << " nanoseconds" << endl;
  return 0;
}
