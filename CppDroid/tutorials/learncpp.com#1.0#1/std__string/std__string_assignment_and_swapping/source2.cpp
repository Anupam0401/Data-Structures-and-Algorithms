const string sSource("abcdefg");
string sDest;

sDest.assign(sSource, 2, 4); // assign a substring of source from index 2 of length 4
cout << sDest << endl;