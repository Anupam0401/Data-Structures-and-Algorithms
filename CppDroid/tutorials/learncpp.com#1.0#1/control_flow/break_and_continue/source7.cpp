int nPrinted = 0;

for (int iii=0; iii < 100; iii++)
{
    // if the number is divisible by 3 or 4, skip this iteration
    if ((iii % 3)==0 || (iii % 4)==0)
        continue;

    cout << iii << endl;
    nPrinted++;
}

cout << nPrinted << " numbers were found" << endl;