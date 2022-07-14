
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
 
#define MAXC 15
#define MAXW 100

typedef struct
{
	char word[MAXC];
	char sorted[MAXC];
}word_t;


int readwords(word_t wordlist[]);
void sortword(word_t *pword);
int is_anagram(word_t *pword1,word_t *pword2);
void sortwordlist(word_t wordlist[],int numwords);
void printanagrams(word_t wordlist[],int numwords);


int main()
{
	word_t wordlist[MAXW];
	word_t *p1, *p2;

	int numwords = readwords(wordlist);
	
//	printf("%d",numwords);
	p1 = wordlist;

	for(int i=0; i<numwords; i++)
	{
		sortword(p1);
		p1++;
	}


/*	for(int i=0; i<numwords; i++)
		printf("\n%s",wordlist[i].sorted);*/

	sortwordlist(wordlist,numwords);
	printf("\n\n");


/*	for(int i=0; i<numwords; i++)
		printf("\n%s",wordlist[i].sorted);*/
	  printanagrams(wordlist,numwords);

	return 0;
}


int readwords(word_t wordlist[])
{
	int count = 0;int n;
	printf("enter the number of words \n");
	scanf("%d",&n);
	printf("\nEnter the words with size less than 15.\n");

	for(int i=0; i<n; i++)
	{

		if(i)
		{
			if(strcmp(wordlist[i-1].word,"\0") == 0)
				return count - 1;
		}

		printf("\nEnter the word %d : ",i+1);
		
	    scanf("%s",wordlist[i].word);
       	//gets(wordlist[i].word);	
	printf("\n%s\n",wordlist[i].word);
		count = count + 1;
	}

	return count;
}

void sortword(word_t *pword)
{
    char temp[MAXC];

    int size = strlen(pword->word);
    
    strcpy(temp,pword->word);
    
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(temp[i] > temp[j])
            {
                char a = temp[i];
                temp[i] = temp[j];
                temp[j] = a;
            }
        }
    }

    strcpy(pword->sorted,temp);
}

int is_anagram(word_t *pword1,word_t *pword2)
{
	//firstly we will sort the words for comparison

	sortword(pword1);
	sortword(pword2);

	if(strcmp(pword1->sorted,pword2->sorted) == 0)   //checking the word is anagram or not
		return 1;                                    //it is anagram 

	else 
		return 0;                                    //it is not an anagram
}

/*void sortwordlist(word_t wordlist[],int numwords)
{
	

	for(int i=0;i<numwords-1;i++)
	{
		for(int j=i+1;j<numwords-1;j++)
		{
			if(strcmp(wordlist[j].sorted,wordlist[j+1].sorted) > 0)
			{
				char temp[MAXC] = "\0";
				strcpy(temp,wordlist[j].sorted);
				strcpy(wordlist[j].sorted,wordlist[j+1].sorted);
				strcpy(wordlist[j+1].sorted,temp);
			}
		}
	}
}*/
void sortwordlist(word_t wordlist[],int numwords)
{
    for(int i=0;i<=numwords-1;i++)
	{
		for(int j=i+1;j<=numwords-1;j++)
		{
		    word_t *ptr1,*ptr2;
		    ptr1=&wordlist[i];
		    ptr2=&wordlist[j];
		    if(strcmp(ptr1->sorted,ptr2->sorted)>0)
		    {
		        char temp1[MAXC]="\0";
		        char temp2[MAXC]="\0";
		        strcpy(temp1,ptr1->sorted);
		        strcpy(temp2,ptr1->word);
				strcpy(ptr1->sorted,ptr2->sorted);
				strcpy(ptr1->word,ptr2->word);
				strcpy(ptr2->sorted,temp1);
				strcpy(ptr2->word,temp2);
		    }
		}
	}
}
    


void printanagrams(word_t wordlist[],int numwords)
{
	sortwordlist(wordlist,numwords);
	word_t *pword1,*pword2;
	printf("\n%s\t",wordlist[0].word);
	for(int i=0; i<numwords; i++)
	{
	    pword1=&wordlist[i];
	    pword2=&wordlist[i+1];
	    
		if(is_anagram(pword1,pword2))
		    printf("%s\t",wordlist[i+1].word);
		else
		    printf("\n%s\t",wordlist[i+1].word);
	    
	    
	}
}
