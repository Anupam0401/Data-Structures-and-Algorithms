cout << sizeof(szString) << endl;
for (int nChar = 0; nChar < sizeof(szString); nChar++)
    cout << static_cast<int>(szString[nChar]) << " ";