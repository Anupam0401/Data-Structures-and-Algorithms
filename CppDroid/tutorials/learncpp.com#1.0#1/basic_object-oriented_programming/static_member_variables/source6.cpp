class Something
{
private:
    static int s_nIDGenerator;
    int m_nID;
public:
    Something() { m_nID = s_nIDGenerator++; }

    int GetID() const { return m_nID; }
};

int Something::s_nIDGenerator = 1;

int main()
{
    Something cFirst;
    Something cSecond;
    Something cThird;

    using namespace std;
    cout << cFirst.GetID() << endl;
    cout << cSecond.GetID() << endl;
    cout << cThird.GetID() << endl;
    return 0;
}