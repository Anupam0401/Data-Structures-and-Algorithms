try
{
    throw 5; // throw an int exception
}
catch (double dX)
{
    cout << "We caught an exception of type double: " << dX << endl;
}
catch (...) // catch-all handler
{
    cout << "We caught an exception of an undetermined type" << endl;
}