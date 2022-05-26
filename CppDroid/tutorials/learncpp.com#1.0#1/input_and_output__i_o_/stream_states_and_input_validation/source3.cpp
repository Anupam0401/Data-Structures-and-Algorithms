bool InputMatches(string strUserInput, string strTemplate)
{
    if (strTemplate.length() != strUserInput.length())
        return false;

    // Step through the user input to see if it matches
    for (unsigned int nIndex=0; nIndex < strTemplate.length(); nIndex++)
    {
        switch (strTemplate[nIndex])
        {
            case '#': // match a digit
                if (!isdigit(strUserInput[nIndex]))
                    return false;
                break;
            case '_': // match a whitespace
                if (!isspace(strUserInput[nIndex]))
                    return false;
                break;
            case '@': // match a letter
                if (!isalpha(strUserInput[nIndex]))
                    return false;
                break;
            case '?': // match anything
                break;
            default: // match the exact character
                if (strUserInput[nIndex] != strTemplate[nIndex])
                    return false;
        }
    }

    return true;
}

int main()
{
    string strValue;

    while (1)
    {
        cout << "Enter a phone number (###) ###-####: ";
        getline(cin, strValue); // get the entire line, including spaces
        if (InputMatches(strValue, "(###) ###-####"))
            break;
    }

    cout << "You entered: " << strValue << endl;
}