stringstream os;
os << "Hello ";

os.str(""); // erase the buffer

os << "World!";
cout << os.str();