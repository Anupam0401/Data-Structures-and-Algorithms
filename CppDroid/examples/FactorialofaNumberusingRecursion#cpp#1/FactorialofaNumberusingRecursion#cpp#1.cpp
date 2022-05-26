/*
Summary: Factorial is represented using '!', so five factorial will be written as (5!),n factorial as (n!).Also
n! = n*(n-1)*(n-2)*(n-3)...3.2.1 and zero factorial is defined as one i.e. 0! = 1.
*/

 #include<iostream>

using namespace std;

int fact(int);
int main(){
  int num,f;
  cout<<"\nEnter a number: ";
  cin>>num;
  f=fact(num);
  cout<<"\nFactorial of "<<num<<" is: "<<f;
  return 0;
}
//recursive function
int fact(int n){
   if(n==1)
       return 1;
   else
       return(n*fact(n-1));
 }

/*
Input: Enter a number: 5
*/