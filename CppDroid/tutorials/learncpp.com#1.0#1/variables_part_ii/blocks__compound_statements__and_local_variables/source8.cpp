int main()
{ // outer block
    int nValue = 5;

    if (nValue >= 5)
    { // nested block
        int nValue = 10;
        // nValue now refers to the nested block nValue.
        // the outer block nValue is hidden
    } // nested nValue destroyed

    // nValue now refers to the outer block nValue

    return 0;
} // outer nValue destroyed