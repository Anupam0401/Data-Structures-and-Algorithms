int main()
{
    // Declare a non-pointer Storage to show it works
    Storage<int> cIntStorage(5);

    // Declare a pointer Storage to show it works
    int x = 7;
    Storage<int*> cIntPtrStorage(&x);

    // If cIntPtrStorage did a pointer assignment on x,
    // then changing x will change cIntPtrStorage too
    x = 9;
    cIntPtrStorage.Print();

    return 0;
}