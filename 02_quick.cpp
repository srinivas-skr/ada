#include<iostream>
using namespace std;

int dividearray(int arr[], int lb, int ub)   // lb= lower bound and ub= upper bound
{
    int pivot = arr[lb];
    int pos = lb;
    for(int i = pos + 1; i <= ub; i++)
    {
        if(arr[i] < pivot)
        {
            pos++;
            swap(arr[pos], arr[i]);
        }
    }
    swap( arr[lb],arr[pos]);  
    return pos;
}

void quicksort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int p = dividearray(arr, lb, ub);
        quicksort(arr, lb, p - 1);
        quicksort(arr, p + 1, ub);
    }
}

void printarray(int arr[], int n)
{
    for(int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter size of  the array: ";
    cin >> size;
    
    int array[size];
    cout << "Enter " << size << " numbers: ";
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
    quicksort(array, 0, size - 1);     // sorted array
    cout << "Sorted array: ";
    printarray(array, size);
    return 0;
}
