string sString("01234567");
cout << "Length: " << sString.length() << endl;
cout << "Capacity: " << sString.capacity() << endl;

sString.reserve(200);
cout << "Length: " << sString.length() << endl;
cout << "Capacity: " << sString.capacity() << endl;

sString.reserve();
cout << "Length: " << sString.length() << endl;
cout << "Capacity: " << sString.capacity() << endl;