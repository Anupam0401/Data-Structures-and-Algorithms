#include<bits/stdc++.h>
using namespace std;
int size = 0;
void swap(int *a, int *b) { //takes O(1) time
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to heapify the priority queue
void heapify(int array[], int size, int i) { 
    if (size == 1) {
        printf("Single element in the heap");
    } 
    else {
        // Find the largest among root, left child and right child
        int largest = i;
        int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
  }
}

// Function to insert an element into the max priority queue
void build_MaxHeap(int array[], int newNum) { 
    if (size == 0) {
        array[0] = newNum;
        size += 1;
    }
    else {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(array, size, i);
        }
    }
}
//function which deletes the root(max element) and heapifies the remaining priority queue
int extract_Max(int array[]) { 
  int x=array[0];
  swap(&array[0], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
  return x;
}
// Print the array
void printArray(int array[], int size) { 
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    cout<<"Enter the number of elements (integer) : ";
    int n;
    cin>>n;
    int array[n];
    int a;
    int b[n]={0};
    cout<<"\n\nEnter the elements seperated by spaces : ";
    for(int i = 0; i < n; i++) {
        cin>>a;
        build_MaxHeap(array , a);
    }
    int k;
    cout<<"\nEnter the value of k: ";
    cin>>k;
    int ans = 0;
    for(int i = 0; i <k ; i++) {
        ans = extract_Max(array);
    }
    if(k==1)
        cout<<"The largest element is "<<ans<<endl;
    else if(k==2)
        cout<<"The 2nd largest element is "<<ans<<endl;
    else if(k==3)
        cout<<"The 3rd largest element is "<<ans<<endl;
    else
        cout<<"The "<<k<<"th largest element is "<<ans<<endl;
    return 0;
}