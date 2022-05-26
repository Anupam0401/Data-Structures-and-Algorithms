int main()
{
    // do not declare y here
    {
        // y is only used inside this block, so declare it here
        int y = 5;
        cout << y;
    }
    // otherwise y could still be used here
}