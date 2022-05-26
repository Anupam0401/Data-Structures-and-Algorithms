void CountDown(int nValue)
{
    using namespace std;
    cout << nValue << endl;

    // termination condition
    if (nValue > 0)
        CountDown(nValue-1);
}

int main(void)
{
    CountDown(10);
    return 0;
}