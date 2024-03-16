#include<iostream>
using namespace std;

void merge(int a[], int lb, int mid, int ub) {
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 = ub - mid;
    
    int LeftArray[n1], RightArray[n2];
    
    for (i = 0; i < n1; i++)
        LeftArray[i] = a[lb + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = lb;
    
    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        } else {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    
    while (j < n2) {
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

void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
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
  
mergeSort(a, 0, n - 1);
  cout << "Sorted array: ";
  printArray(array, size);
  return 0;
}
