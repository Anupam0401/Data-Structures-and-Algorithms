template<int nSize>
void PrintBufferString(Buffer<char, nSize> &rcBuf)
{
	std::cout << rcBuf.GetBuffer() << std::endl;
}