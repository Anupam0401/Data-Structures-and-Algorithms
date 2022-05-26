int Add(int nX, int nY)
{
    return nX + nY;
}

int main()
{
    // Create a function pointer and make it point to the Add function
    int (*pFcn)(int, int) = Add;
    cout << pFcn(5, 3) << endl; // add 5 + 3

    return 0;
}