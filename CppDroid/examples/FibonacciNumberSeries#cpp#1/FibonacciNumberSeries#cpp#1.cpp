/*
Summary: Fibonacci Sequence is the series of numbers:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34,...
*/



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
     
	// Variable Declaration
     int counter, n;
     long last=1,next=0,sum;
     // Get Input Value
     cout<<"Enter the Number :";
     cin>>n;
     //Fibonacci Series Calculation
     while(next<n/2)
     {
      cout<<last <<"+";
      sum=next+last;
      next=last;
      last=sum;
     }
     // Wait For Output Screen
     return 0;
 }



/*
Input: Enter number of terms: 10
*/