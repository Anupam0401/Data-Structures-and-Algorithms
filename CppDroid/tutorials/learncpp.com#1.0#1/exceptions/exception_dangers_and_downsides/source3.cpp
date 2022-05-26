try
{
    Person *pJohn = new Person("John", 18, E_MALE);
    ProcessPerson(pJohn);
    delete pJohn;
}
catch (PersonException &cException)
{
    cerr << "Failed to process person: " << cException.what() << endl;
}