bool EvensFirst(int nX, int nY)
{
        // if nX is not even and nY is, nY goes first
	if ((nX % 2) && !(nY % 2))
		return false;

        // if nX is even and nY is not, nX goes first
	if (!(nX % 2) && (nY % 2))
		return true;

        // otherwise sort in Ascending order
	return Ascending(nX, nY);
}

int main()
{
    using namespace std;

    int anArray[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    SelectionSort(anArray, 9, EvensFirst);
    PrintArray(anArray, 9);

    return 0;
}