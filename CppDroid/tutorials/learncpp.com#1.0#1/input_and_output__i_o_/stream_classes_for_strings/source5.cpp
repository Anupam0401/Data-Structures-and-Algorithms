stringstream os;

int nValue = 12345;
double dValue = 67.89;
os << nValue << " " << dValue;

string strValue1, strValue2;
os >> strValue1 >> strValue2;

cout << strValue1 << " " << strValue2 << endl;