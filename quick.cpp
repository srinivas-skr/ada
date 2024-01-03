#include<iostream>
using namespace std;

int dividearray (int arr[], int lb, int ub)   // lb= lower bound and ub= upper bound
{
	int pivot= arr[lb];
	int i = lb;
	for(int j=i+1; j<=ub; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[lb],arr[i]);	
	return i;
}


void quicksort (int arr[], int lb, int ub)
{
if(lb < ub)
	{
		int p= dividearray(arr, lb, ub );
		quicksort(arr, lb, p-1);
		quicksort(arr, p+1, ub);
	}
}

void printarray(int arr[], int size)
{
 for(int a=0; a<size; a++) 
 {
   cout<< arr[a] <<" " ;
 }
cout<< endl ;
}

int main()
{
	int arr[]= {5, 3, 1, 9, 8, 2, 4, 7};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<< "original array: ";
	printarray(arr,n);
	
	// sorted array
	quicksort(arr, 0, n-1);
	cout<<"sorted array: ";
	printarray(arr, n);
	return 0;
}