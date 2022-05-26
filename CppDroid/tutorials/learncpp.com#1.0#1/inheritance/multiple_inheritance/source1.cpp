#include <string>
class Person
{
private:
    std::string m_strName;
    int m_nAge;
    bool m_bIsMale;

public:
    Person(std::string strName, int nAge, bool bIsMale)
        : m_strName(strName), m_nAge(nAge), m_bIsMale(bIsMale)
    {
    }

    std::string GetName() { return m_strName; }
    int GetAge() { return m_nAge; }
    bool IsMale() { return m_bIsMale; }
};

class Employee
{
private:
    std::string m_strEmployer;
    double m_dWage;

public:
    Employee(std::string strEmployer, double dWage)
        : m_strEmployer(strEmployer), m_dWage(dWage)
    {
    }

    std::string GetEmployer() { return m_strEmployer; }
    double GetWage() { return m_dWage; }
};

// Teacher publicly inherits Person and Employee
class Teacher: public Person, public Employee
{
private:
     int m_nTeachesGrade;

public:
    Teacher(std::string strName, int nAge, bool bIsMale, std::string strEmployer, double dWage, int nTeachesGrade)
        : Person(strName, nAge, bIsMale), Employee(strEmployer, dWage), m_nTeachesGrade(nTeachesGrade)
    {
    }
};