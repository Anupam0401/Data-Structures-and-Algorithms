/*
Summary: Fibonacci Sequence is the series of numbers:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34,...
*/

#include <stdio.h> 
int main() { 
	int count, n, t1=0, t2=1, display=0;

	printf("Enter number of terms: "); 
	scanf("%d",&n); 

	/* Displaying first two terms */ 
	printf("Fibonacci Series: %d+%d+", t1, t2); 

	count=2;
	/* count=2 because first two terms are already displayed. */ 
	while (count<n) {
	//add first two
		display=t1+t2;
	//set first no. value to second
		t1=t2;
	//set second no. value to result of addition
		t2=display;
	//increment count
		++count; 
		printf("%d+",display);
	} 
	return 0;
} 

/*
Input: Enter number of terms: 10
*/