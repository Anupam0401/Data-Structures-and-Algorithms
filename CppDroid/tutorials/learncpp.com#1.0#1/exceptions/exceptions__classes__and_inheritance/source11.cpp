try
{
     // code using standard library goes here
}
// This handler will catch std::exception and all the derived exceptions too
catch (std::exception &cException)
{
    cerr << "Standard exception: " << cException.what() << endl;
}