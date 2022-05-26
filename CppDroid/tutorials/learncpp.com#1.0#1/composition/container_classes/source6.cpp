// Reallocate resizes the array.  Any existing elements will be destroyed.
    // This function operates quickly.
    void Reallocate(int nNewLength)
    {
        // First we delete any existing elements
        Erase();

        // If our array is going to be empty now, return here
        if (nNewLength<= 0)
            return;

        // Then we have to allocate new elements
        m_pnData = new int[nNewLength];
        m_nLength = nNewLength;
    }

    // Resize resizes the array.  Any existing elements will be kept.
    // This function operates slowly.
    void Resize(int nNewLength)
    {
        // If we are resizing to an empty array, do that and return
        if (nNewLength <= 0)
        {
            Erase();
            return;
        }

        // Now we can assume nNewLength is at least 1 element.  This algorithm
        // works as follows: First we are going to allocate a new array.  Then we
        // are going to copy elements from the existing array to the new array.
        // Once that is done, we can destroy the old array, and make m_pnData
        // point to the new array.

        // First we have to allocate a new array
        int *pnData = new int[nNewLength];

        // Then we have to figure out how many elements to copy from the existing
        // array to the new array.  We want to copy as many elements as there are
        // in the smaller of the two arrays.
        if (m_nLength > 0)
        {
            int nElementsToCopy = (nNewLength > m_nLength) ? m_nLength : nNewLength;

            // Now copy the elements one by one
            for (int nIndex=0; nIndex < nElementsToCopy; nIndex++)
                pnData[nIndex] = m_pnData[nIndex];
        }

        // Now we can delete the old array because we don't need it any more
        delete[] m_pnData;

        // And use the new array instead!  Note that this simply makes m_pnData point
        // to the same address as the new array we dynamically allocated.  Because
        // pnData was dynamically allocated, it won't be destroyed when it goes out of scope.
        m_pnData = pnData;
        m_nLength = nNewLength;
    }