#include <iostream>
#include <algorithm>
using namespace std;

void MergeSort(int arr[], int lowerBound, int upperBound) {
    if (lowerBound < upperBound) {
        int mid = lowerBound + (upperBound - lowerBound) / 2;
        MergeSort(arr, lowerBound, mid);
        MergeSort(arr, mid + 1, upperBound);
        inplace_merge(arr + lowerBound, arr + mid + 1, arr + upperBound + 1); // to merge two sorted sub-arrays
    }
}

void printArray(int arr[], int n) {
    for (int a = 0; a < n; a++) {
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
    cout << "Array after merge sort: ";
    printArray(arr, size);
    return 0;
}
