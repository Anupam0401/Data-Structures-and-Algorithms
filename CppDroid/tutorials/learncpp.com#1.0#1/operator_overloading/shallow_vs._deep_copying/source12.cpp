class MyString
{
private:
    char *m_pchString;
    int m_nLength;

    MyString(const MyString& cSource);
    MyString& operator=(const MyString& cSource);
public:
    // Rest of code here
};