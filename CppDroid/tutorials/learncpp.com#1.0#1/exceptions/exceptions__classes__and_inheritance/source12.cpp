try
{
     // code using standard library goes here
}
// This handler will catch std::bad_alloc (and any exceptions derived from it) here
catch (std::bad_alloc &cException)
{
    cerr << "You ran out of memory!" << endl;
}
// This handler will catch std::exception (and any exception derived from it) that fall
// through here
catch (std::exception &cException)
{
    cerr << "Standard exception: " << cException.what() << endl;
}