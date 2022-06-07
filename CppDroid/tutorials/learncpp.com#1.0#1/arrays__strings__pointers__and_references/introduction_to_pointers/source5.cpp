int nValue = 5;
cout << &nValue; // prints address of nValue
cout << nValue; // prints contents of nValue

int *pnPtr = &nValue; // pnPtr points to nValue
cout << pnPtr; // prints address held in pnPtr, which is &nValue
cout << *pnPtr; // prints contents pointed to by pnPtr, which is contents of nValue