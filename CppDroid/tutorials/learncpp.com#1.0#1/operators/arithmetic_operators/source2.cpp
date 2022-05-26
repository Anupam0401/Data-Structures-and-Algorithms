bool IsEven(int x)
{
    // if x % 2 == 0, 2 divides evenly into our number
    // which means it must be an even number
    if (x % 2 == 0)
        return true;
    else
        return false;
}