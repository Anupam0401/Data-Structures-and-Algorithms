int foo(int nX)
{
}

int (*pFoo)(int) = foo; // assign pFoo to foo()

(*pFoo)(nValue); // call function foo(nValue) through pFoo.