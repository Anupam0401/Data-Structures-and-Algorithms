#include <string>
class Animal
{
protected:
    std::string m_strName;

public:
    Animal(std::string strName)
        : m_strName(strName)
    {
    }

    std::string GetName() { return m_strName; }
    virtual const char* Speak() = 0; // pure virtual function
};