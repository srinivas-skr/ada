#include <iostream>

using namespace std;

void merge(int a[], int low, int mid, int high);

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) {
    int res[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = a[j++];
        }
    }
    while (i <= mid) {
        res[k++] = a[i++];
    }
    while (j <= high) {
        res[k++] = a[j++];
    }
    for (int p = 0; p < k; ++p) {
        a[low + p] = res[p];
    }
}

int main() {
    cout << "Enter the number of files: ";
    int size;
    cin >> size;
    
    int array[size];
    cout << "Enter the elements : \n";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    mergeSort(a, 0, n - 1);

    cout << "Sorted elements :\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}
