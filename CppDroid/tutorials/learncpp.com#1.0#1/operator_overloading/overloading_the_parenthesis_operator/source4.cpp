#include <cassert> // for assert()
class Matrix
{
private:
    double adData[4][4];
public:
    Matrix()
    {
        // Set all elements of the matrix to 0.0
        for (int nCol=0; nCol<4; nCol++)
            for (int nRow=0; nRow<4; nRow++)
                adData[nRow][nCol] = 0.0;
    }

    double& operator()(const int nCol, const int nRow);
    void operator()();
};

double& Matrix::operator()(const int nCol, const int nRow)
{
    assert(nCol >= 0 && nCol < 4);
    assert(nRow >= 0 && nRow < 4);

    return adData[nRow][nCol];
}

void Matrix::operator()()
{
    // reset all elements of the matrix to 0.0
    for (int nCol=0; nCol<4; nCol++)
        for (int nRow=0; nRow<4; nRow++)
            adData[nRow][nCol] = 0.0;
}