#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
        
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    cout << "Enter the size of array: ";
    int size;
    cin >> size;

    vector<int> arr(size);
    cout << "Enter " << size << " numbers ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    heapSort(arr);
    cout << "Sorted array: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
