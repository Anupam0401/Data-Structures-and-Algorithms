char szSource[] = "Copy this!";
char szDest[50];
strncpy(szDest, szSource, 49); // copy at most 49 characters (indices 0-48)
szDest[49] = 0; // ensures the last character is a null terminator
cout << szDest; // prints "Copy this!"