int main()
{
    char strBuf[100];
    cin.getline(strBuf, 100);
    cout << strBuf << endl;
    cout << cin.gcount() << " characters were read" << endl;

    return 0;
}