template <typename T, int nSize>
void PrintBufferString(Buffer<T, nSize> &rcBuf)
{
    std::cout << rcBuf.GetBuffer() << std::endl;
}