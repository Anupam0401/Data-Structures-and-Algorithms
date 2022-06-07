int main()
{
    try
    {
        throw 4.5; // throw exception of type double
        cout << "This never prints" << endl;
    }
    catch(double dX) // handle exception of type double
    {
        cerr << "We caught a double of value: " << dX << endl;
    }
}