class addressBookType: public extPersonType

{

public:

    addressBookType();

    void setInfo(string);

    void nameSort();

    void nameSearch(string);

    void bDaySearch(int);

    void printInfo() const;

    void printNames() const;

    void printRange(string, string) const;

    void printType(string) const;

private:

    static const int MAX_ENTRIES = 2;

    extPersonType addrBook[MAX_ENTRIES];

    ifstream inF;



};



#endif 



addressBookTypeImp.cpp



#include "addressBookType.h"

#include <iostream>



using namespace std;



addressBookType::addressBookType(){

}



void addressBookType::setInfo(string file){

    string fName, lName;

    int aMonth, aDay, aYear;

    string addr, cit, sta;

    int zip;

    string type;

    long int phone;

    inF.open(file.c_str());

    for(int i = 0; i < MAX_ENTRIES; i++){

        inF >> fName >> lName >> aMonth

            >> aDay >> aYear >> addr >> cit

            >> sta >> zip >> type >> phone;

        addrBook[i].setExtPersonType(fName, lName, aMonth, aDay, aYear,

                                     addr, cit, sta, zip, type, phone);

    }

    inF.close();

}



void addressBookType::printInfo() const{

    for(int i = 0; i < MAX_ENTRIES; i++){

        addrBook[i].printExtPersonType();

        cout << endl;

    }

}



void addressBookType::nameSort(){

    extPersonType temp;

    for(int i = 1; i < MAX_ENTRIES; i++){

        for(int j = 0; j < MAX_ENTRIES-1; j++){

            if(addrBook[j].getLastName() > addrBook[j+1].getLastName()){

                temp = addrBook[j];

                addrBook[j] = addrBook[j+1];

                addrBook[j+1] = temp;

            }

        }

    }

}



void addressBookType::nameSearch(string choice){

    cout << "Returning results for " << choice << ": "<< endl;

    for (int i = 0; i < MAX_ENTRIES; i++){

        if(addrBook[i].getLastName() == choice)

            addrBook[i].printExtPersonType();

    }

}



void addressBookType::bDaySearch(int month){

    for(int i = 0; i < MAX_ENTRIES; i++){

        if(addrBook[i].getBday() == month){

            addrBook[i].printNames();

            cout << endl;

        }

    }

}



void addressBookType::printRange(string first, string last) const{

    for(int i = 0; i < MAX_ENTRIES; i++){

        if(first <= addrBook[i].getLastName()

           && addrBook[i].getLastName() <= last){

            addrBook[i].printNames();

            cout << endl;

        }

    }

}



void addressBookType::printType(string choice) const{

    for(int i = 0; i < MAX_ENTRIES; i++){

        if(addrBook[i].getType() == choice){

            addrBook[i].printNames();

            cout << endl;

        }

    }

}



addressType.h



#ifndef ADDRESSTYPE_H

#define ADDRESSTYPE_H

#include <string>

using namespace std;



class addressType

{

public:

    addressType(string = "", string = "", string = "", int = 0);

    void setAddressType(string, string, string, int);

    void getAddressType(string&, string&, string&, int&);

    void setAddress(string);

    string getAddress() const;

    void setCity(string);

    string getCity() const;

    void setState(string);

    string getState() const;

    void setZip(int);

    int getZip() const;

    void print() const;

private:

    string address;

    string city;

    string state;

    int zipCode;

};



#endif



addressTypeImp.cpp



#include <iostream>

#include "addressType.h"

using namespace std;



addressType::addressType(string addr, string cit,

                         string sta, int zip){

    setAddressType(addr, cit, sta, zip);

}



void addressType::setAddressType(string addr, string cit,

                                 string sta, int zip){

    address = addr;

    city = cit;

    state = sta;

    zipCode = zip;

}



void addressType::getAddressType(string& addr, string& cit,

                                 string& sta, int& zip){

    addr = address;

    cit = city;

    sta = state;

    zip = zipCode;

}



void addressType::setAddress(string addr){

    address = addr;

}



string addressType::getAddress() const{

    return address;

}



void addressType::setCity(string cit){

    city = cit;

}



string addressType::getCity() const{

    return city;

}



void addressType::setState(string sta){

    state = sta;

}



string addressType::getState() const{

    return state;

}



void addressType::setZip(int zip){

    zipCode = zip;

}



int addressType::getZip() const{

    return zipCode;

}



void addressType::print() const{

    cout << "Address: " << address << endl;

    cout << "City: " << city << endl;

    cout << "State: " << state << endl;

    cout << "Zip: " << zipCode << endl;

}



extPersonType.h



#ifndef EXTPERSONTYPE_H

#define EXTPERSONTYPE_H

#include <string>

#include "personType.h"

#include "dateType.h"

#include "addressType.h"

using namespace std;



class extPersonType

{

public:

    extPersonType(string first = "", string last = "",

                  int month = 0, int day = 0, int year = 0,

                  string addr = "", string cit = "",string sta = "",

                  int zip = 0, string pType = "", long int phone = 0);

    void setExtPersonType(string first, string last, int month,

                          int day, int year, string addr, string cit,

                          string sta, int zip, string pType, long int phone);

    void printExtPersonType() const;

    void printNames() const;

    string getLastName() const;

    string getType() const;

    int getBday() const;

private:

    personType name;

    dateType birthday;

    addressType address;

    string type;

    long int phoneNum;

};



#endif





extPersonTypeImp.cpp



#include <iostream>

#include "extPersonType.h"

using namespace std;



extPersonType::extPersonType(string first, string last,

                             int month, int day, int year,

                             string addr, string cit,

                             string sta, int zip, string pType,

                             long int phone)

        : name(first, last), birthday(month, day, year),

          address(addr, cit, sta, zip){

    type = pType;

    phoneNum = phone;

}



void extPersonType::setExtPersonType(string first, string last,

                                     int month, int day, int year,

                                     string addr, string cit,

                                     string sta, int zip, string pType,

                                     long int phone){

    name.setName(first, last);

    birthday.setDate(month, day, year);

    address.setAddressType(addr, cit, sta, zip);

    type = pType;

    phoneNum = phone;

}



void extPersonType::printExtPersonType() const{

    cout << "Name: ";

    name.print();

    cout << endl << "Birthdate: ";

    birthday.print();

    cout << endl;

    address.print();

    cout << "Type: " << type << endl;

    cout << "Phone #: " << phoneNum;

}



void extPersonType::printNames() const{

    name.print();

}



string extPersonType::getLastName() const{

    return name.getLastName();

}



int extPersonType::getBday() const{

    return birthday.getMonth();

}



string extPersonType::getType() const{

    return type;

}





main.cpp



#include <iostream>

#include <fstream>

#include "addressType.h"

#include "personType.h"

#include "dateType.h"

#include "extPersonType.h"

#include "addressBookType.h"

using namespace std;





const int MAX_ENTRIES = 500;



int main()

{

    addressBookType addrObject;

    string searchV, first, last;

    int month;

    addrObject.setInfo("addrData.txt");

    addrObject.nameSort();

    cout << "Please enter your search: ";

    cin >> searchV;

    if(searchV == "bday")

    {

        cout << "Please enter your month: ";

        cin >> month;

        addrObject.bDaySearch(month);

    }

    if(searchV == "range")

    {

        cout << "Please enter the two names: ";

        cin >> first >> last;

        addrObject.printRange(first, last);

    }

    if(searchV == "family" || searchV == "friend"

       || searchV == "associate")

    {

        addrObject.printType(searchV);

    }

    else

        addrObject.nameSearch(searchV);



}