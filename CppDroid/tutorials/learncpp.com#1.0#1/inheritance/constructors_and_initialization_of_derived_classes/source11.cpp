int main()
{
    BaseballPlayer cPlayer("Pedro Cerrano", 32, true, 0.342, 42);

    using namespace std;
    cout << cPlayer.m_strName << endl;
    cout << cPlayer.m_nAge << endl;
    cout << cPlayer.m_nHomeRuns;

    return 0;
}