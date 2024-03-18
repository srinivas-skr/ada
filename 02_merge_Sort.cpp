#include<iostream>
using namespace std;

void merge(int a[], int lb, int mid, int ub) {
    int i, j, k;
    int s1 = mid - lb+1 ;
    int s2 = ub - mid;
    
    int LeftArray[s1], RightArray[s2];
    
    for (i = 0; i < s1; i++)
        LeftArray[i] = a[lb + i];
    for (j = 0; j < s2; j++)
        RightArray[j] = a[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = lb;
    
    while (i < s1 && j < s2) {
        if (LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        } else {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    
    while (i < s1) {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    
    while (j < s2) {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
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
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
  
    mergeSort(array, 0, size - 1); 
    cout << "Sorted array: ";
    printArray(array, size); 
    return 0;
}
