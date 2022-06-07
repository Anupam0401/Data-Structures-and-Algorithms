const int nSize = 5;
int anArray[nSize] = { 30, 50, 20, 10, 40 };

// Step through each element of the array
for (int nStartIndex = 0; nStartIndex < nSize; nStartIndex++)
{
    // nSmallestIndex is the index of the smallest element
    // we've encountered so far.
    int nSmallestIndex = nStartIndex;

    // Search through every element starting at nStartIndex+1
    for (int nCurrentIndex = nStartIndex + 1; nCurrentIndex < nSize; nCurrentIndex++)
    {
        // If the current element is smaller than our previously found smallest
        if (anArray[nCurrentIndex] < anArray[nSmallestIndex])
            // Store the index in nSmallestIndex
            nSmallestIndex = nCurrentIndex;
    }

    // Swap our start element with our smallest element
    swap(anArray[nStartIndex], anArray[nSmallestIndex]);
}