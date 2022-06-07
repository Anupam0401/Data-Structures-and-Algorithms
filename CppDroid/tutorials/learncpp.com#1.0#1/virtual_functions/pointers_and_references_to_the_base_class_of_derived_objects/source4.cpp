#include <string>
class Animal
{
protected:
    std::string m_strName;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string strName)
        : m_strName(strName)
    {
    }

public:
    std::string GetName() { return m_strName; }
    const char* Speak() { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(std::string strName)
        : Animal(strName)
    {
    }

    const char* Speak() { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string strName)
        : Animal(strName)
    {
    }

    const char* Speak() { return "Woof"; }
};

int main()
{
    Cat cCat("Fred");
    cout << "cCat is named " << cCat.GetName() << ", and it says " << cCat.Speak() << endl;

    Dog cDog("Garbo");
    cout << "cDog is named " << cDog.GetName() << ", and it says " << cDog.Speak() << endl;

    Animal *pAnimal = &cCat;
    cout << "pAnimal is named " << pAnimal->GetName() << ", and it says " << pAnimal->Speak() << endl;

    Animal *pAnimal = &cDog;
    cout << "pAnimal is named " << pAnimal->GetName() << ", and it says " << pAnimal->Speak() << endl;

    return 0;
}