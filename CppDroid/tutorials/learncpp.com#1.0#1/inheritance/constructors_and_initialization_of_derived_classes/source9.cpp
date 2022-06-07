// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double m_dBattingAverage;
    int m_nHomeRuns;

    BaseballPlayer(std::string strName = "", int nAge = 0, bool bIsMale = false,
        double dBattingAverage = 0.0, int nHomeRuns = 0)
        : Person(strName, nAge, bIsMale), // call Person(std::string, int, bool) to initialize these fields
            m_dBattingAverage(dBattingAverage), m_nHomeRuns(nHomeRuns)
    {
    }
};