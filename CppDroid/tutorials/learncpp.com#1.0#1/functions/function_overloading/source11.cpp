class X; // with user-defined conversion to int

void Print(float fValue);
void Print(int nValue);

X cValue; // declare a variable named cValue of type class X
Print(cValue); // cValue will be converted to an int and matched to Print(int)