#include<iostream>

#define N 10

using namespace std;

void max_heapify(int* array, int index) //1-based index
{
    int leftChildIndex = 2*index;       //  these two lines 
    int rightChildIndex = 2*index + 1;  //                  are possible because we assumed 1-based index was passed to this function
    int largest;
    
    if(leftChildIndex<=N && array[leftChildIndex-1]>array[index-1]) //again, because of 1-based indexing
        largest = leftChildIndex;
    else
        largest = index;

    if(rightChildIndex<=N && array[rightChildIndex-1]>array[largest-1]) //1-based indexing
        largest = rightChildIndex;

    if(largest!=index)
    {
        swap(array[index-1], array[largest-1]);
        max_heapify(array, largest);
    }
}

void build_maxHeap(int* array)
{
    for(int i=N/2;i>0;i--)
        max_heapify(array,i);   //notice how 1-based index of the lowest-rightmost internal node, up till the root node, is iterated
}

int main()
{

    int inputArray[N];
    cout<<"Enter 10 values for input array"<<endl;
    for(int i=0;i<N;i++)
        cin>>inputArray[i];

    build_maxHeap(inputArray);  //no need to worry about 1-based or 0-based indexing here

    cout<<"Here is the input array turned into a max heap:";
    for(int i=0;i<N;i++)
        cout<<inputArray[i]<<" ";
    cout<<endl;

    return 0;
}