#include <bits/stdc++.h>
using namespace std;

class Car
{
public:
    string name;
    int model_no;
    int years_of_use;
    int insurance;
};

int main()
{
    Car lambo;
    lambo.insurance = 10;
    lambo.years_of_use = 5;
    lambo.name = "Lamborghini";
    lambo.model_no = 1;
    cout<<lambo.name<<endl;
    return 0;
}