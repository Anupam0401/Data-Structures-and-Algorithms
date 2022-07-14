#include<bits/stdc++.h>
using namespace std;
int size = 0;
void swap(int *a, int *b) { //takes O(1) time
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to heapify the priority queue
void heapify(int array[], int size, int i) { //takes O(log n) time
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
void enqueue(int array[], int newNum) { 
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
int deleteRoot(int array[]) { //takes O(n.log n) time
  int x=array[0];
  swap(&array[0], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
  return x;
}
// Print the array
void printArray(int array[], int size) { //takes O(n) time
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    int array[n];
    int a;
    int b[n]={0};
    cout<<"\n\nEnter the integers seperated by spaces : ";
    for(int i = 0; i < n; i++) {
        cin>>a;
        enqueue(array , a);
        for(int j=0;j<=i;j++) {
            b[j] = deleteRoot(array);
        }
        for(int j=0;j<=i;j++) {
            enqueue(array, b[j]);
        }
        if(i%2==0)
                cout<<b[i/2]<<" ";
            else
                cout<<(b[int(i/2)]+b[int(i/2)+1]) / 2.0<<" ";
    }
    return 0;
}