ofstream outf("Sample.dat");
outf << "This is line 1" << endl;
outf << "This is line 2" << endl;
outf.close(); // explicitly close the file

// Oops, we forgot something
outf.open("Sample.dat", ios::app);
outf << "This is line 3" << endl;
outf.close();