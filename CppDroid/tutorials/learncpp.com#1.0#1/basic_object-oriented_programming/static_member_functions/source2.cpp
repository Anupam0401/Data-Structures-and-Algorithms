class Something
{
private:
    static int s_nValue;
public:
    static int GetValue() { return s_nValue; }
};

int Something::s_nValue = 1; // initializer

int main()
{
    std::cout << Something::GetValue() << std::endl;
}