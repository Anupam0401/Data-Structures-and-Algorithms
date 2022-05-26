string sSource("sphinx of black quartz, judge my vow");

char szBuf[20];
int nLength = sSource.copy(szBuf, 5, 10);
szBuf[nLength]='\0';  // Make sure we terminate the string in the buffer

cout << szBuf << endl;