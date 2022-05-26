const int nSize = 5;
int anArray[nSize] = { 30, 50, 20, 10, 40 };

// Step through each element of the array
for (int nStartIndex = 0; nStartIndex < nSize; nStartIndex++)
{
    // nLargestIndex is the index of the largest element
    // we've encountered so far.
    int nLargestIndex = nStartIndex;

    // Search through every element starting at nStartIndex+1
    for (int nCurrentIndex = nStartIndex + 1; nCurrentIndex < nSize; nCurrentIndex++)
    {
        // If the current element is smaller than our previously found smallest
        if (anArray[nCurrentIndex] > anArray[nLargestIndex])
            // Store the index in nLargestIndex
            nLargestIndex = nCurrentIndex;
    }

    // Swap our start element with our largest element
    swap(anArray[nStartIndex], anArray[nLargestIndex]);
}