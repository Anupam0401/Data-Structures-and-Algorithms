#include <string>
using namespace std;

class Teacher
{
private:
    string m_strName;
public:
    Teacher(string strName)
        : m_strName(strName)
    {
    }

    string GetName() { return m_strName; }
};

class Department
{
private:
    Teacher *m_pcTeacher; // This dept holds only one teacher

public:
    Department(Teacher *pcTeacher=NULL)
        : m_pcTeacher(pcTeacher)
    {
    }
};

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher *pTeacher = new Teacher("Bob"); // create a teacher
    {
        // Create a department and use the constructor parameter to pass
        // the teacher to it.
        Department cDept(pTeacher);

    } // cDept goes out of scope here and is destroyed

    // pTeacher still exists here because cDept did not destroy it
    delete pTeacher;
}