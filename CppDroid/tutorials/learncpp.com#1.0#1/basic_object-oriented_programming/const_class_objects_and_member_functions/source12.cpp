void PrintDate(const Date &cDate)
{
    // although cDate is const, we can call const member functions
    std::cout << cDate.GetMonth() << "/" <<
        cDate.GetDay() << "/" <<
        cDate.GetYear() << std::endl;
}

int main()
{
    const Date cDate(10, 16, 2020);
    PrintDate(cDate);

    return 0;
}