string sSource("abcdefg");
char *szString = "abcdefg";
// memcmp compares the first n characters of two C-style strings and returns 0 if they are equal
if (memcmp(sSource.data(), szString, sSource.length()) == 0)
    cout << "The strings are equal";
else
    cout << "The strings are not equal";