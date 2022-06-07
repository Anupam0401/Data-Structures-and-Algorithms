string sString;

// Assign a string value
sString = string("One");
cout << sString << endl;

const string sTwo("Two");
sString.assign(sTwo);
cout << sString << endl;

// Assign a C-style string
sString = "Three";
cout << sString << endl;

sString.assign("Four");
cout << sString << endl;

// Assign a char
sString = '5';
cout << sString << endl;

// Chain assignment
string sOther;
sString = sOther = "Six";
cout << sString << " " << sOther << endl;