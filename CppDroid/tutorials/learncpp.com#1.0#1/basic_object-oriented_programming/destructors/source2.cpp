int main()
{
    MyString cMyName("Alex");
    std::cout << "My name is: " << cMyName.GetString() << std::endl;
    return 0;
} // cMyName destructor called here!