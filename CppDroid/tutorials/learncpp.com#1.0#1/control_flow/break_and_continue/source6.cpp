int nPrinted = 0;

for (int iii=0; iii < 100; iii++)
{
    // messy!
    if ((iii % 3) && (iii % 4))
    {
        cout << iii << endl;
        nPrinted++;
    }
}

cout << nPrinted << " numbers were found" << endl;