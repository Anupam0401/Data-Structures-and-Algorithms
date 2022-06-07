int add(int x, int y, int z)
{
    return x + y + z;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()

{
    cout << multiply(add(1, 2, 3), 4) << endl;
    return 0;
}