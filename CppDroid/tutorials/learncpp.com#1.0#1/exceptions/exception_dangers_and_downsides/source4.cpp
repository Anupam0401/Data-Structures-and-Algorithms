Person *pJohn = NULL;
try
{
    pJohn = new Person("John", 18, E_MALE);
    ProcessPerson(pJohn );
    delete pJohn;
}
catch (PersonException &cException)
{
    delete pJohn;
    cerr << "Failed to process person: " << cException.what() << endl;
}