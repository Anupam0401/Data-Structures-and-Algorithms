// Declare a DateStruct variable
DateStruct sToday;

// Initialize it manually
sToday.nMonth = 10;
sToday.nDay = 14;
sToday.nYear = 2020;

// Here is a function to initialize a date
void SetDate(DateStruct &sDate, int nMonth, int nDay, int Year)
{
    sDate.nMonth = nMonth;
    sDate.nDay = nDay;
    sDate.nYear = nYear;
}

// Init our date to the same date using the function
SetDate(sToday, 10, 14, 2020);