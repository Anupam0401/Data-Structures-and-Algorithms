int main()
{
    // declare a char buffer
    Buffer<char, 10> cChar10Buffer;

    // copy a value into the buffer
    strcpy(cChar10Buffer.GetBuffer(), "Ten");

    // Print the value
    PrintBufferString(cChar10Buffer);
    return 0;
}