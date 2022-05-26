int x = 5;
x = x - 2;
cout << x << endl; // #1

int y = x;
cout << y << endl; // #2

// x + y is an r-value in this context, so evaluate their values
cout << x + y << endl; // #3

cout << x << endl; // #4

int z;
cout << z << endl; // #5