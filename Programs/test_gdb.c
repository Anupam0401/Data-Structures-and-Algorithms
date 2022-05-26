#include<stdio.h>
int main()
{
    int a=5,b=5;
    for(int i=0;i<10;i++)
    {
        int c = b++/a--;
        printf("%d ",c);
    }
    return 0;
}
