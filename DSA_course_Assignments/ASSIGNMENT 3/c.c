#include<stdio.h>
#include<stdlib.h>
int n;
 typedef struct{
  int *info;
  int top;
  int limit;
 }STACK;
void stackpermutation(int a1[],int b1[],int c1[],int in,int st,int ou);
void push(int a1[],int b1[],int c1[],int in,int st,int ou);
void pop(int a1[],int b1[],int c1[],int in,int st,int ou);
int* createstack();
int* createqueue();
 static int ns=0;
int main(){
int i;
  printf("Enter the no of elements\n");
 scanf("%d",&n);
 
 int *a,*b,*c;
 a=createqueue();
 b=createstack();
 c=createqueue();
 printf("Enter the numbers\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Possible outcomes\n");
 stackpermutation(a,b,c,n,0,0);
 printf("No of posiible outcomes\n");
 printf("%d\n",ns);
 return 0;
 }
 int* createstack()
 {
  STACK s;
  s.info=(int *)malloc(n*sizeof(int));
  s.top=-1;
  s.limit=n-1;
  return (int*)s.info;
 }
 int* createqueue()
 {
  int *p;
  p=(int *)malloc(n*sizeof(int));
  return p;
 }

 void push(int a1[],int b1[],int c1[],int in,int st,int ou)
{
 b1[st]=a1[0];
 st++;
 
 
 for(int i=0;i<in-1;i++)
 {
  a1[i]=a1[i+1];
 }
 in--;
 int a2[n],b2[n],c2[n];
 for(int i=0;i<in;i++)
 {
  a2[i]=a1[i];
 }
 for(int i=0;i<st;i++)
 {
  b2[i]=b1[i];
 }
 for(int i=0;i<ou;i++)
 {
  c2[i]=c1[i];
 }
 stackpermutation(a2,b2,c2,in,st,ou);
}
void pop(int a1[],int b1[],int c1[],int in,int st,int ou)
{
 c1[ou]=b1[st-1];
 st--;
 ou++;
 int a2[n],b2[n],c2[n];
  for(int i=0;i<in;i++)
 {
  a2[i]=a1[i];
 }
 for(int i=0;i<st;i++)
 {
  b2[i]=b1[i];
 }
 for(int i=0;i<ou;i++)
 {
  c2[i]=c1[i];
 }
 stackpermutation(a2,b2,c2,in,st,ou);
 }
void stackpermutation(int a1[],int b1[],int c1[],int in,int st,int ou)
{
 if(st==0)
 {
  if(in==0)
  {
   for(int i=0;i<n;i++)
   {
    printf("%d ",c1[i]);
   }
   ns+=1;
   printf("\n");
  }
 else if(in!=0)
 {
  push(a1,b1,c1,in,st,ou);
 }
 }
 else if(in==0)
 {
  pop(a1,b1,c1,in,st,ou);
 }
 else
 {
  pop(a1,b1,c1,in,st,ou);
  push(a1,b1,c1,in,st,ou);
 } 
} 
