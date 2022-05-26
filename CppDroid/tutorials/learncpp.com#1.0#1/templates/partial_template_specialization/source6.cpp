int main()
{
    Buffer<char, 10> cChar10Buffer;
    Buffer<char, 11> cChar11Buffer;

    strcpy(cChar10Buffer.GetBuffer(), "Ten");
    strcpy(cChar11Buffer.GetBuffer(), "Eleven");

    PrintBufferString(cChar10Buffer);
    PrintBufferString(cChar11Buffer); // this will not compile

    return 0;
}