class Something
{
public:
    static int s_nValue;
};

int Something::s_nValue = 1;

int main()
{
    Something cFirst;
    cFirst.s_nValue = 2;

    Something cSecond;
    std::cout << cSecond.s_nValue;

    return 0;
}