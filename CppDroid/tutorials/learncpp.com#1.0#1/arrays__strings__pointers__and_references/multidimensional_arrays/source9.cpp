// Declare a 10x10 array
const int nNumRows = 10;
const int nNumCols = 10;
int nProduct[nNumRows ][nNumCols ] = { 0 };

// Calculate a multiplication table
for (int nRow = 0; nRow < nNumRows; nRow++)
    for (int nCol = 0; nCol < nNumCols; nCol++)
        nProduct[nRow][nCol] = nRow * nCol;

// Print the table
for (int nRow = 1; nRow < nNumRows; nRow++)
{
    for (int nCol = 1; nCol < nNumCols; nCol++)
        cout << nProduct[nRow][nCol] << "\t";

    cout << endl;
}