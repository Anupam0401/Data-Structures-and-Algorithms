int main()
{
    // declare an int buffer
    Buffer<int, 10> cInt10Buffer;

    // copy values into the buffer
    for (int nCount=0; nCount < 10; nCount++)
        cInt10Buffer[nCount] = nCount;

    // Print the value?
    PrintBufferString(cInt10Buffer); // what does this mean?
    return 0;
}