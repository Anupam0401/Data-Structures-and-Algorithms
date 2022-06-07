int ReadNumber();
void WriteAnswer(int x);

int main()
{
    int x = ReadNumber();
    int y = ReadNumber();
    WriteAnswer(x+y);
    return 0;
}