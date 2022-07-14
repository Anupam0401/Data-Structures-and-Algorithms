#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct tnode
{
	int exp;
	float coeff;
	struct tnode *next;
}poly;


poly *createTerm(int expo,float coef);
poly *insert(poly *head,int expo,float coef);
poly *readpoly(int numterms);
void printpoly(poly *head);
float evalpoly(poly *head,float x);
poly *addpoly(poly *head1,poly *head2);
poly *multiplypoly(poly *head1,poly *head2);


int main()
{
	poly *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
	int n;
	printf("Enter the number of terms of 1st polynomial : ");
	scanf("%d",&n);
	printf("\n");

	poly1 = readpoly(n);

	printf("\nEnter the number of terms of 2nd polynomial : ");
	scanf("%d",&n);
	printf("\n");

	poly2 = readpoly(n);

	printf("POLYNOMIAL 1: \n");
	printpoly(poly1);

	printf("POLYNOMIAL 2: \n");
	printpoly(poly2);

	float x;
	printf("Enter the value of (x) : ");
	scanf("%f",&x);

	printf("------------------------------------------------\n");
	printf("The value of polynomial P1 at x = %f = %f\n",x,evalpoly(poly1,x));
	printf("The value of polynomial P2 at x = %f = %f\n",x,evalpoly(poly2,x));
	printf("------------------------------------------------\n");


	poly3 = addpoly(poly1,poly2);
	printf("\nAfter adding the two polynomials P1 and P2 we get : \n");
	printpoly(poly3);

	return 0;
}


//this function inputs the polynomial from the user
poly *readpoly(int numterms)
{
	poly *head = NULL, *temp = NULL;
	int expo;
	float coef;
	for(int i=0; i<numterms; i++)
	{
		printf("Enter (exponent,coefficient) : ");
		scanf("%d%f",&expo,&coef);
		head = insert(head,expo,coef);
	}

	return head;
}


//function to create a new term(NODE)
poly *createTerm(int expo,float coef)
{
	poly *p = NULL;

	p = (poly *)malloc(sizeof(poly));

	if(p == NULL)
	{
		return p;
	}

	p -> exp = expo;
	p -> coeff = coef;
	p -> next = NULL;

	return p;
}


//function to insert a new node into the list
poly *insert(poly *head,int expo,float coef)
{
	//checking the head node is present or not
	if(head == NULL)
	{
		head = createTerm(expo,coef);
		if(head == NULL)
		{
			printf("Failed to create the node.\n");
			return head;
		}
		return head;
	}

	//creating the new node
	poly *newNode;
	newNode = createTerm(expo,coef);

	if(newNode == NULL)
	{
		printf("Failed to create node.\n");
		return newNode;
	}

	//checking if the node should be at the begning or not
	if((newNode -> exp) > (head -> exp))
	{
		newNode -> next = head;
		return newNode;
	}

	//if the previous condition is not satisfied then we have to find the correct position of the node
	poly *temp = NULL;
	temp = head;

	while(((temp -> next) != NULL) && ((temp -> exp) > expo))
    {
        if(((temp -> next) -> exp) < expo)
            break;
		temp = temp -> next;
    }

	newNode -> next = temp -> next;
	temp -> next = newNode;

	return head;
}


//function for printing the polynomial
void printpoly(poly *head)
{
	poly *current = head;
	printf("\n");
	printf("\t%f(x)^%d",current -> coeff,current -> exp);
	current = current -> next;
	while(current != NULL)
	{
		if((current -> coeff) == 0)		//if coefficient = 0 then dont print that term
			current = current -> next;
		else if((current -> coeff) < 0)
		{
			printf(" %f(x)^%d",current -> coeff,current -> exp);
			current = current -> next;
		}
		else
		{
			printf(" + %f(x)^%d",current -> coeff,current -> exp);
			current = current -> next;
		}
	}

	printf("\n");
}


//function for evaluating the value of polynomial at any value of (x)
float evalpoly(poly *head,float x)
{
	poly *current = head;
	float value = 0;
	while(current != NULL)
	{
		value += pow(x,current -> exp)*(current -> coeff);
		current = current -> next;
	}
	return value;
}


//this function adds two polynoials that was taken input by the user
poly *addpoly(poly *head1,poly *head2)
{
	int e;
	float c;
	poly *temp = NULL;
	poly *p1 = head1;
	poly *p2 = head2;
	while((p1 != NULL) || (p2 != NULL))
	{
		if((p1 != NULL) && (p2 != NULL))
		{
			printf("A\n");
			if((p1 -> exp) == (p2 -> exp))
			{
				printf("a\n");
				e = (p1 -> exp);
				c = (p1 -> coeff) + (p2 -> coeff);
				temp = insert(temp,e,c);
				p1 = p1 -> next;
				p2 = p2 -> next;
			}
			else if((p1 -> exp) > (p2 -> exp))
			{
				printf("b\n");
				e = p1 -> exp;
				c = p1 -> coeff;
				temp = insert(temp,e,c);
				p1 = p1 -> next;
			}
			else
			{
				printf("c\n");
				e = p2 -> exp;
				c = p2 -> coeff;
				temp = insert(temp,e,c);
				p2 = p2 -> next;
			}
		}
		else if((p1 == NULL) && (p2 != NULL))
		{
			printf("B\n");
			e = p2 -> exp;
			c = p2 -> coeff;
			temp = insert(temp,e,c);
			p2 = p2 -> next;
		}
		else if((p1 != NULL) && (p2 == NULL))
		{
			printf("C\n");
			e = p1 -> exp;
			c = p1 -> coeff;
			temp = insert(temp,e,c);
			p1 = p1 -> next;
		}
	}

	return temp;
}
