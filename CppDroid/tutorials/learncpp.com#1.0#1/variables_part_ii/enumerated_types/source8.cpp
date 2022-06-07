int ParseFile()
{
    if (!OpenFile())
        return -1;
    if (!ReadFile())
        return -2;
    if (!Parsefile())
        return -3;

    return 0; // success
}