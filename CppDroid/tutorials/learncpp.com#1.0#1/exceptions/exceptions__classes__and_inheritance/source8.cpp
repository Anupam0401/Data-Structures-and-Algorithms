try
{
    // do some stuff with the standard library here
}
catch (std::exception &cException)
{
    cerr << "Standard exception: " << cException.what() << endl;
}