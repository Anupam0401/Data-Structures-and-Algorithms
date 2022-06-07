int anArray[5]; // Ok -- 5 is a literal constant

#define ARRAY_SIZE 5
int anArray[ARRAY_SIZE]; // Ok -- ARRAY_SIZE is a symbolic constant

const int nArraySize = 5;
int anArray[nArraySize]; // Ok -- nArraySize is a variable constant

enum ArrayElements
{
    MAX_ARRAY_SIZE = 5;
};
int anArray[MAX_ARRAY_SIZE]; // Ok -- MAX_ARRAY_SIZE is an enum constant

int nSize = 5;
int anArray[nSize]; // Not ok! -- nSize is not a constant!