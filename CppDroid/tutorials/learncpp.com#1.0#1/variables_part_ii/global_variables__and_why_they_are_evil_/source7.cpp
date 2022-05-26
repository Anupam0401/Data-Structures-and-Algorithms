int nValue = 5;

int main()
{
    int nValue = 7; // hides the global nValue variable
    nValue++; // increments local nValue, not global nValue
    ::nValue--; // decrements global nValue, not local nValue
    return 0;
} // local nValue is destroyed