// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_dBattingAverage;
    int m_nHomeRuns;

    BaseballPlayer(double dBattingAverage = 0.0, int nHomeRuns = 0)
       : m_dBattingAverage(dBattingAverage), m_nHomeRuns(nHomeRuns)
    {
    }
};