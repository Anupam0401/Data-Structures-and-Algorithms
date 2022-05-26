cout.fill('*');
cout << -12345 << endl; // print default value with no field width
cout << setw(10) << -12345 << endl; // print default with field width
cout << setw(10) << left << -12345 << endl; // print left justified
cout << setw(10) << right << -12345 << endl; // print right justified
cout << setw(10) << internal << -12345 << endl; // print internally justified