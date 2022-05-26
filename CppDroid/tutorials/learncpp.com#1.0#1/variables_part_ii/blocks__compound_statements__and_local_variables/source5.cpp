void someFunction()
{
    int nValue;
}

int main()
{
    // nValue can not be seen inside this function.

    someFunction();

    // nValue still can not be seen inside this function.

    return 0;
}