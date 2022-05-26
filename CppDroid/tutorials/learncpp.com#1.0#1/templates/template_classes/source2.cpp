#ifndef DOUBLEARRAY_H
#define DOUBLEARRAY_H

#include <assert.h> // for assert()

class DoubleArray
{
private:
    int m_nLength;
    double *m_pdData;

public:
    DoubleArray()
    {
        m_nLength = 0;
        m_pdData= 0;
    }

    DoubleArray(int nLength)
    {
        m_pdData= new double[nLength];
        m_nLength = nLength;
    }

    ~DoubleArray()
    {
        delete[] m_pdData;
    }

    void Erase()
    {
        delete[] m_pdData;
        // We need to make sure we set m_pnData to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_pdData= 0;
        m_nLength = 0;
    }

    double& operator[](int nIndex)
    {
        assert(nIndex >= 0 && nIndex < m_nLength);
        return m_pdData[nIndex];
    }

    // The length of the array is always an integer
    // It does not depend on the data type of the array
    int GetLength() { return m_nLength; }
};

#endif