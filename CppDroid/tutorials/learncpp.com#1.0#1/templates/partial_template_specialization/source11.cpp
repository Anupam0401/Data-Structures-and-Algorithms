using namespace std;

template <typename T>
class Storage<T*> // this is specialization of Storage that works with pointer types
{
private:
    T* m_tValue;
public:
    Storage(T* tValue) // for pointer type T
    {
         m_tValue = new T(*tValue);
    }

    ~Storage()
    {
        delete m_tValue;
    }

    void Print()
    {
        std::cout << *m_tValue << std::endl;
    }
};