#include<iostream>
using namespace std;

// implement min heap

class MinHeap
{
private:
    int *arr;
    int size;
    int capacity;
    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l<size && arr[l]<arr[i])
        {
            smallest = l;
        }
        if(r<size && arr[r]<arr[smallest])
        {
            smallest = r;
        }
        if(smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }
    void insert(int data)
    {
        if(size == capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }
        size++;
        arr[size-1] = data;
        for(int i=size-1; i!=0 && arr[parent(i)]>arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    int extractMin()
    {
        if(size<=0)
        {
            return INT_MAX;
        }
        if(size==1)
        {
            size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapify(0);
        return root;
    }
    void print()
    {
        for(int i=0; i<size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    h.print();
    cout << h.extractMin() << endl;
    h.print();
    cout << h.extractMin() << endl;
    h.print();
    cout << h.extractMin() << endl;
    h.print();
    cout << h.extractMin() << endl;
    h.print();
    cout << h.extractMin() << endl;
    h.print();
    cout << h.extractMin() << endl;
    h.print();
    return 0;
}