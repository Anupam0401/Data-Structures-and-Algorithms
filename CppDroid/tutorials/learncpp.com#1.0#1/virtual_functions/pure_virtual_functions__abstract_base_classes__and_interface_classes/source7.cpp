class Cow: public Animal
{
public:
    Cow(std::string strName)
        : Animal(strName)
    {
    }

    virtual const char* Speak() { return "Moo"; }
};

int main()
{
    Cow cCow("Betsy");
    cout << cCow.GetName() << " says " << cCow.Speak() << endl;
}