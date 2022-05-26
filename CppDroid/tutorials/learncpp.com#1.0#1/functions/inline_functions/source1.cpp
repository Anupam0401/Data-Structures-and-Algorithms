int min(int nX, int nY)
{
    return nX > nY ? nY : nX;
}

int main()
{
    using namespace std;
    cout << min(5, 6) << endl;
    cout << min(3, 2) << endl;
    return 0;
}