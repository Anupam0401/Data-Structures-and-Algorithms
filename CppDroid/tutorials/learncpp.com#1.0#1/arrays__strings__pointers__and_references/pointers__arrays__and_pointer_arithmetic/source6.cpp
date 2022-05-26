const int nArraySize = 7;
char szName[nArraySize] = "Mollie";
int nVowels = 0;
for (char *pnPtr = szName; pnPtr < szName + nArraySize; pnPtr++)
{
    switch (*pnPtr)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            nVowels++;
            break;
    }
}

cout << szName << " has " << nVowels << " vowels" << endl;