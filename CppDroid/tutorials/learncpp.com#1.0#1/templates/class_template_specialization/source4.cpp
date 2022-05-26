int main()
{
    // Define a Storage8 for integers (instantiates Storage8<T>, where T = int)
    Storage8<int> cIntStorage;

    for (int nCount=0; nCount<8; nCount++)
        cIntStorage[nCount] = nCount;

    for (int nCount=0; nCount<8; nCount++)
        std::cout << cIntStorage[nCount] << std::endl;

    // Define a Storage8 for bool  (instantiates Storage8<bool> specialization)
    Storage8<bool> cBoolStorage;
    for (int nCount=0; nCount<8; nCount++)
        cBoolStorage.Set(nCount, nCount & 3);

    for (int nCount=0; nCount<8; nCount++)
        std::cout << (cBoolStorage.Get(nCount) ? "true" : "false") << std::endl;

    return 0;
}