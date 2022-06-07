void AddOne(int &y)
{
    y++;
}

int main()
{
    int x = 5;

    cout << "x = " << x << endl;
    AddOne(x);
    cout << "x = " << x << endl;

    return 0;
}