#include<stdio.h>
#include<stdlib.h>

 int n;

typedef struct
{
  
int *data;
   
int top;
   
int maximum;
 
} STACK;

 
static int ns = 0;

 
int *
stackformation () 
{
  
STACK s;
  
s.data = (int *) malloc (n * sizeof (int));
  
s.top = -1;
  
s.maximum = n - 1;
  
return (int *) s.data;

} 
int *

queueformation () 
{
  
int *p;
  
p = (int *) malloc (n * sizeof (int));
  
return p;

}


 
void
push (int p[], int q[], int r[], int input, int st, int output) 
{
  
q[st] = p[0];
  
st++;
  
 
 
for (int i = 0; i < input - 1; i++)
    
    {
      
p[i] = p[i + 1];
    
} 
input--;
  
int a2[n], b2[n], c2[n];
  
for (int i = 0; i < input; i++)
    
    {
      
a2[i] = p[i];
  
} 
for (int i = 0; i < st; i++)
    
    {
      
b2[i] = q[i];
  
} 
for (int i = 0; i < output; i++)
    
    {
      
c2[i] = r[i];
    
} 
stackpermutation (a2, b2, c2, input, st, output);

} 
void

pop (int p[], int q[], int r[], int input, int s, int output) 
{
  
r[output] = q[s - 1];
  
s--;
  
output++;
  
int a2[n], b2[n], c2[n];
  
for (int i = 0; i < input; i++)
    
    {
      
a2[i] = p[i];
  
} 
for (int i = 0; i < s; i++)
    
    {
      
b2[i] = q[i];
  
} 
for (int i = 0; i < output; i++)
    
    {
      
c2[i] = r[i];
    
} 
stackpermutation (a2, b2, c2, input, s, output);

} 
void

stackpermutation (int p[], int q[], int r[], int input, int s, int output) 
{
  
if (s == 0)
    
    {
      
if (input == 0)
	
	{
	  
for (int i = 0; i < n; i++)
	    
	    {
	      
printf ("%d ", r[i]);
	    
} 
ns = ns + 1;
	  
printf ("\n");
	
}
      
      else if (input != 0)
	
	{
	  
push (p, q, r, input, s, output);
	
}
    
}
  
  else if (input == 0)
    
    {
      
pop (p, q, r, input, s, output);
    
}
  
  else
    
    {
      
pop (p, q, r, input, s, output);
      
push (p, q, r, input, s, output);
    
}

}


 
int
main ()
{
  
int i;
  
printf ("Enter the number of digits you want to enter\n");
  
scanf ("%d", &n);
  
 
int *a1, *a2, *a3;
  
a1 = queueformation ();
  
a2 = stackformation ();
  
a3 = queueformation ();
  
printf ("Enter the number's digit one by one\n");
  
for (i = 0; i < n; i++)
    
    {
      
scanf ("%d", &a1[i]);
    
}
  
printf ("The qualifying stack permutations are as follows:\n");
  
stackpermutation (a1, a2, a3, n, 0, 0);
  
printf ("Total number of stack permutations are\n");
  
printf ("%d\n", ns);
  
return 0;

}


 
