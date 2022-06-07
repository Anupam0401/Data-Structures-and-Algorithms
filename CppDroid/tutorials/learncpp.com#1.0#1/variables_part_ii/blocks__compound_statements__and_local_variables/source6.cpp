int main()
{
    int nValue = 5;

    { // begin nested block
        double dValue = 4.0;
    } // dValue destroyed here

    // dValue can not be used here because it was already destroyed!

    return 0;
} // nValue destroyed here