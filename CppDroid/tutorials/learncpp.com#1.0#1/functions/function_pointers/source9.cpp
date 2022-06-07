void SelectionSort(int *anArray, int nSize)
{
    using namespace std;
    for (int nStartIndex= 0; nStartIndex < nSize; nStartIndex++)
    {
        int nBestIndex = nStartIndex;

        // Search through every element starting at nStartIndex+1
        for (int nCurrentIndex = nStartIndex + 1; nCurrentIndex < nSize; nCurrentIndex++)
        {
            // Note that we are using the user-defined comparison here
            if (anArray[nCurrentIndex] < anArray[nBestIndex]) // COMPARISON DONE HERE
                nBestIndex = nCurrentIndex;
        }

        // Swap our start element with our best element
        swap(anArray[nStartIndex], anArray[nBestIndex]);
    }
}