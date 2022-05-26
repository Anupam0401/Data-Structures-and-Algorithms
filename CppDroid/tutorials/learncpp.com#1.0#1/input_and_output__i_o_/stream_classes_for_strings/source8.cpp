stringstream os;
os << "Hello ";

os.str(std::string()); // erase the buffer

os << "World!";
cout << os.str();