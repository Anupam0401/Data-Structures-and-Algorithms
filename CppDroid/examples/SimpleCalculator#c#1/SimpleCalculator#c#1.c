/*
Summary: Does addition subtraction multiplication division
*/

# include <stdio.h>
int main()  { 
	char operator; 
	float num1,num2; 

	printf("Enter operator either + or - or * or divide : ");
	scanf("%c",&operator);

	printf("Enter two operands: ");
	scanf("%f%f",&num1,&num2);

	switch(operator) { 
		case '+': 
		printf("num1+num2=%.2f",num1+num2); 
		break; 
		case '-':
		printf("num1-num2=%.2f",num1-num2); 
		break; 
		case '*':
		printf("num1*num2=%.2f",num1*num2); 
		break;
		case '/':
		printf("num2/num1 = %.2f",num1/num2); 
		break;
		default: 
	/* If operator is other than +, -, * or /, error message is shown */ 
		printf("Error! operator is not correct");
		break;
	} 
	return 0;
} 

/*
Input: Enter operator either + or - or * or divide: /
Enter two operands: 13.456
4.56
*/