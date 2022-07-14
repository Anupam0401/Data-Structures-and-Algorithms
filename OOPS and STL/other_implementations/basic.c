#include<stdio.h>
int main()
{
char ch;
int a;
scanf("%c %d",&ch,&a);
int result=sizeof(ch)*sizeof(97)%sizeof(100);
result=result*(sizeof(char)+sizeof(int));
result=result>sizeof(ch);
result=ch*result+a+ch;
printf("%d",result);
return 0;
}
