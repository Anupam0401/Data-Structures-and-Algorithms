int main()
{
    // declare an integer buffer with room for 12 chars
    Buffer<char, 10> cChar10Buffer;
    Buffer<char, 11> cChar11Buffer;

    // strcpy a string into the buffer and print it
    strcpy(cChar10Buffer.GetBuffer(), "Ten");
    strcpy(cChar11Buffer.GetBuffer(), "Eleven");

    PrintBufferString(cChar10Buffer);
    PrintBufferString(cChar11Buffer);

    return 0;
}