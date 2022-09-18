// implement max heap in cpp
#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int *arr;
    int size;
    int capacity;
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < size && arr[l] > arr[i])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(largest);
        }
    }
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

public:
    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }
    void insert(int data)
    {
        if (size == capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }
        size++;
        arr[size - 1] = data;
        for (int i = size - 1; i != 0 && arr[parent(i)] < arr[i];)
        {
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }
    int extractMax()
    {
        if (size <= 0)
            return -1;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    MaxHeap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(80);
    h.insert(90);
    h.insert(100);
    h.print();
    cout << h.extractMax() << endl;
    h.print();
    return 0;
}