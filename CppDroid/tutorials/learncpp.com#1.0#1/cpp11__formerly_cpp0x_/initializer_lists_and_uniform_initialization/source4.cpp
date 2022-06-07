#include <vector>
#include <initializer_list>

using namespace std;

template <typename T>
class MyArray
{
private:
    vector<T> m_Array;

public:
    MyArray() { }

    MyArray(const initializer_list<T>& il)
    {
        // Manually populate the elements of the array from initializer_list x
        for (auto x: il) // use range-based for statement to iterate over the elements of the initializer list
            m_Array.push_back(x); // push them into the array manually
    }
};

int main()
{
    MyArray<int> foo = { 3, 4, 6, 9 };
    return 0;
}