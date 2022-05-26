using namespace std;
int Calculate(int nX, int nY, char chOperator)
{
    switch (chOperator)
    {
        case '+':
            return nX + nY;
        case '-':
            return nX - nY;
        case '*':
            return nX * nY;
        case '/':
            return nX / nY;
        default:
            cout << "Error" << endl;
            exit(1);
    }
}