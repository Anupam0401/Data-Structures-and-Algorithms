#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int MaxElement_BS(int arr[], int low, int high);

int main()
{
    cout << "Enter the number of elements in array" << endl;
    int arr_size = 0;
    cin>>arr_size;
    int arr[arr_size];
    cout<<"\nEnter the array" << endl;
    for(int i=0; i<arr_size;i++)
    {
        cin>>arr[i];
    }
	cout << "\nThe maximum element is " << MaxElement_BS(arr, 0, arr_size-1)<<endl;
	return 0;
}
int MaxElement_BS(int arr[], int low, int high)
{
	if (low == high)    //1 element case
		return arr[low];
	
	/* 2 elements decreasing*/
	if ((high == low + 1) && arr[low] >= arr[high])
		return arr[low];
	
	/*2 elements increasing*/ 
	if ((high == low + 1) && arr[low] < arr[high])
		return arr[high];
	
	int mid = (low + high)/2;
	
	/* mid element = max*/
	if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
		return arr[mid];
	
	/* max is before mid*/
	if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
		return MaxElement_BS(arr, low, mid-1);
	else
		return MaxElement_BS(arr, mid + 1, high);//max is after mid
}