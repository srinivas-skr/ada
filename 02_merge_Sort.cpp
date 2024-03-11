#include <iostream>
#include <algorithm>
using namespace std;

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        inplace_merge(arr + left, arr + mid + 1, arr + right + 1); // to merge two sorted sub-arrays
    }
}

void printArray(int arr[], int size) {
    for (int a = 0; a < size; a++) {
        cout << arr[a] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter " << size << " numbers ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, 0, size - 1);
    cout << "Sorted Array: ";
    printArray(arr, size);
    return 0;
}
