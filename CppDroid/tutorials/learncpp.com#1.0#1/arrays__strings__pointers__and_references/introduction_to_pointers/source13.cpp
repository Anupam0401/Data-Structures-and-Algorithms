short nValue = 7; // &nValue = 0012FF60
short nOtherValue = 3; // &nOtherValue = 0012FF54
short *pnPtr = &nValue;

cout << &nValue << endl;
cout << nValue << endl;
cout << pnPtr << endl;
cout << *pnPtr << endl;
cout << endl;

*pnPtr = 9;

cout << &nValue << endl;
cout << nValue << endl;
cout << pnPtr << endl;
cout << *pnPtr << endl;
cout << endl;

pnPtr = &nOtherValue;

cout << &nOtherValue << endl;
cout << nOtherValue << endl;
cout << pnPtr << endl;
cout << *pnPtr << endl;
cout << endl;

cout << sizeof(pnPtr) << endl;
cout << sizeof(*pnPtr) << endl;