string sString("0123456789abcde");
cout << "Length: " << sString.length() << endl;
cout << "Capacity: " << sString.capacity() << endl;

// Now add a new character
sString += "f";
cout << "Length: " << sString.length() << endl;
cout << "Capacity: " << sString.capacity() << endl;