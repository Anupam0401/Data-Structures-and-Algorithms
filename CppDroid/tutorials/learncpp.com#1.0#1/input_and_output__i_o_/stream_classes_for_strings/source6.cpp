stringstream os;
os << "12345 67.89"; // insert a string of numbers into the stream
int nValue;
double dValue;

os >> nValue >> dValue;

cout << nValue << " " << dValue << endl;