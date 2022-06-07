class Something
{
private:
    static int s_nValue;

};

int Something::s_nValue = 1; // initializer

int main()
{
    // how do we access Something::s_nValue?
}