#include <memory> // for std::auto_ptr
try
{
    pJohn = new Person("John", 18, E_MALE);
    auto_ptr<Person> pxJohn(pJohn); // pxJohn now owns pJohn

    ProcessPerson(pJohn);

    // when pxJohn goes out of scope, it will delete pJohn
}
catch (PersonException &cException)
{
    cerr << "Failed to process person: " << cException.what() << endl;
}