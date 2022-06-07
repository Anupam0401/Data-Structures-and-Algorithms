string sString("one ");

const string sTemp("twothreefour");
sString.append(sTemp, 3, 5); // append substring of sTemp starting at index 3 of length 5
cout << sString << endl;