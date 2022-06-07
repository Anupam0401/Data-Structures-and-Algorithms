int sum(const initializer_list<int> &il)
{
    int nSum = 0;
    for (auto x: il) // use range-based for statement to iterate over the elements of the initializer list
        nSum += x;
    return nsum;
}

cout << sum( { 3, 4, 6, 9 } );