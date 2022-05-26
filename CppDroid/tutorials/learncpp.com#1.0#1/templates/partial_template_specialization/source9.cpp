using namespace std;

template <typename T>
class Storage
{
private:
    T m_tValue;
public:
    Storage(T tValue)
    {
         m_tValue = tValue;
    }

    ~Storage()
    {
    }

    void Print()
    {
        std::cout << m_tValue << std::endl;;
    }
};