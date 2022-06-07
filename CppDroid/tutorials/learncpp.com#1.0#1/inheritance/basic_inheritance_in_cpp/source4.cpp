#include <iostream>
int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer cJoe;
    // Assign it a name (we can do this directly because m_strName is public)
    cJoe.m_strName = "Joe";
    // Print out the name
    std::cout << cJoe.GetName() << std::endl;

    return 0;
}