/*
Summary: Reverses a given string
*/

#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main( )
{
	clrscr();
	char str[80];
	int temp, l;
	cout<<"Enter string :";
	scanf("%79s",str);
	
	for(l=0;str[l]!='\0';l++);    //finding length of string

	for(int i=0,j=l-1;i<l/2;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;		
	}

	cout<<"Reverse String is\n"<<str;
	
	getch();
	return 0;
}

/*
Input: John
*/