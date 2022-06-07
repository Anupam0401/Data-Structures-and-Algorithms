double Divide(int nX, int nY, bool &bSuccess)
{
    if (nY == 0)
    {
        bSuccess = false;
        return 0.0;
    }

    bSuccess = true;
    return static_cast<double>(nX)/nY;
}

int main()
{
    bool bSuccess; // we must now pass in a bSuccess
    double dResult = Divide(5, 3, bSuccess);

    if (!bSuccess) // and check it before we use the result
        cerr << "An error occurred" << endl;
    else
        cout << "The answer is " << dResult << endl;
}