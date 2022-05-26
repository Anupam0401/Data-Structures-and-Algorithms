// Ask the user to enter a string
char szBuffer[255];
cout << "Enter a string: ";
cin.getline(szBuffer, 255);

int nSpacesFound = 0;
// Loop through all of the characters the user entered
for (int nChar = 0; nChar < strlen(szBuffer); nChar++)
{
    // If the current character is a space, count it
    if (szBuffer[nChar] == ' ')
        nSpacesFound++;
}

cout << "You typed " << nSpacesFound << " spaces!" << endl;