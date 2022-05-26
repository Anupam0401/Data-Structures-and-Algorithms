int Fibonacci(int nNumber)
{
    if (nNumber == 0)
        return 0;
    if (nNumber == 1)
        return 1;
    return Fibonacci(nNumber-1) + Fibonacci(nNumber-2);
}

// And a main program to display the first 13 Fibonacci numbers
int main(void)
{
    using namespace std;
    for (int iii=0; iii < 13; iii++)
        cout << Fibonacci(iii) << " ";

    return 0;
}