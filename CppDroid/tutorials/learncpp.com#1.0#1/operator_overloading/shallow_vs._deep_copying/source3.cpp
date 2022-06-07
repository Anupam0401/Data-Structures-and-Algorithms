MyString cHello("Hello, world!");

{
    MyString cCopy = cHello; // use default copy constructor
} // cCopy goes out of scope here

std::cout << cHello.GetString() << std::endl; // this will crash