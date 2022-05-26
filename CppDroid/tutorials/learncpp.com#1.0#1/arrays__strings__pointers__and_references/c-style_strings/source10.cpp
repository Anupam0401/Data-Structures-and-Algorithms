char szSource[] = "Copy this!";
char szDest[4];
strcpy(szDest, szSource); // buffer overflow!
cout << szDest;