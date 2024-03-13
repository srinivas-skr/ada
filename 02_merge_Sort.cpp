#include <iostream>
#include <algorithm>
using namespace std;

void MergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid + 1, ub);
        inplace_merge(arr + lb, arr + mid + 1, arr + ub + 1); // to merge two sorted sub-arrays
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    
    int array[size];
    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    MergeSort(array, 0, size - 1);
    cout << "Array after merge sort: ";
    printArray(array, size);
    return 0;
}
