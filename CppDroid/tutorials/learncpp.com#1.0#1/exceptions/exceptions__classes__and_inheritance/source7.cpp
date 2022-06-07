try
{
    int nValue = anArray[5];
}
catch (ArrayException &cException)
{
    cerr << "An array exception occurred (" << cException.GetError() << ")" << endl;
}