#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
char st[40];
int top=-1;
void push(char a);
char pop();

int main()
{
    char a[40],t;
    int i=0;
    int f=1;
    cout<<"Enter the expression: ";
    cin>>a;
    while(i < strlen(a))
    {
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
            push(a[i]);
        if(a[i]==')' || a[i]=='}' ||a[i]==']')
        {
            if(top==-1)
            f=0;
            else
            {
            t=pop();
            if(a[i]==')' && (t=='[' || t=='{'))
            f=0;
            if(a[i]=='}' && (t=='(' || t=='['))
            f=0;
            if(a[i]==']' && (t=='{' || t=='('))
            f=0;
            }
        }
        i++;
    }
    if(top>=0)
    f=0;
    if(f==0)
        cout<<"\nNot balanced\n";
    else
        cout<<"\nBalanced\n";
    return 0;
}

void push(char a)
{
    st[++top]=a;
}

char pop()
{
    return st[top--];
}
