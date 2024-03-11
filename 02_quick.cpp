#include<iostream>
using namespace std;

int dividearray(int arr[], int lb, int ub)   // lb= lower bound and ub= upper bound
{
    int pivot = arr[lb];
    int i = lb;
    for(int j = i + 1; j <= ub; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[lb], arr[i]);  
    return i;
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

void printarray(int arr[], int size)
{
    for(int a = 0; a < size; a++) 
    {
        cout << arr[a] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " numbers: ";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printarray(arr, size);
    quicksort(arr, 0, size - 1);     // sorted array
    cout << "Sorted array: ";
    printarray(arr, size);
    return 0;
}
