/*
Summary: Factorial is represented using '!', so five factorial will be written as (5!),n factorial as (n!).
n! = n*(n-1)*(n-2)*(n-3)...3.2.1 and zero factorial is defined as one i.e. 0! = 1.
*/

  //Calling the Header File.
#include<iostream>
//Declaring the main function   
int main()    
{
	//Tells the compiler that we'll be using all the standard C++ library functions
    using namespace std;    
    int num,factorial=1;
	//Ask for the number.
    cout<<"Enter a number to calculate it's factorial"<<endl;  
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        factorial=factorial*i;
    }
    cout<<"Factorial of "<<num<<"="<<factorial<<endl;
    cin.get();
 
    return 0;
}

/*
Input: Enter a number to calculate it's factorial
6
*/