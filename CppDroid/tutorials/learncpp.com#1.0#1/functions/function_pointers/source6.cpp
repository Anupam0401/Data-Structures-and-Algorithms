// function prototypes
int foo();
double goo();
int hoo(int nX);

// function pointer assignments
int (*pFcn1)() = foo; // okay
int (*pFcn2)() = goo; // wrong -- return types don't match!
double (*pFcn3)() = goo; // okay
pFcn1 = hoo; // wrong -- pFcn1 has no parameters, but hoo() does
int (*pFcn3)(int) = hoo; // okay