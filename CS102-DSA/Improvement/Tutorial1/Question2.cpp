#include <cctype>
#include <iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;
int stk[40];
int top = -1;
void push(int x);
int pop();


int main()
{
    char exp[40];
    char *e;
    int n1,n2,n3,num;
    cout<<"Enter a valid postfix expression : ";
    cin>>exp;
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    cout<<"\nResult of the expression "<<exp<<" = "<<pop();
    return 0;
}

void push(int x)
{
    stk[++top] = x;
}

int pop()
{
    return stk[top--];
}
