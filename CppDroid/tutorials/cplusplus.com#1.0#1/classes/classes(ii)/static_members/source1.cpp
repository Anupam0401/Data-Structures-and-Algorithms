// static members in classes
#include <iostream>
using namespace std;

class Dummy {
  public:
    static int n;
    Dummy () { n++; };
    ~Dummy () { n--; };
};

int Dummy::n=0;

int main () {
  Dummy a;
  Dummy b[5];
  Dummy * c = new Dummy;
  cout << a.n << '\n';
  delete c;
  cout << Dummy::n << '\n';
  return 0;
}