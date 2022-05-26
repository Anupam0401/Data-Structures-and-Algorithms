//TIme Complexity-> O(n^2)
//Space COmplexity -> O(n)
//Compile With g++ compiler
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node* next;
};


//function to insert a node at initial position of list
void push(struct Node** head, int num)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//creation new node
    newNode->num = num;
    newNode->next = *head;
    *head = newNode;
}

//function to determine location of insert in list
void insert(struct Node* s[],int num,int x){
    push(&s[x],num);
}

//Function for insertion Sort
void iSort(int arr[], int n)
{
    int i, l, j;
    for (i = 1; i < n; i++)
    {
        l = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > l)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = l;
    }
    
}

//Main logic of Question
void q8sort(int a[],int n,int d){
    int i,j,k,l,x,y,count;
        struct Node* s[d+1];
        int siz[d+1];
        for(i=0;i<d;i++){       //Intialising Arrays will NULL and 0 values
            s[i]=NULL;
            siz[i]=0;
        }
        struct Node* temp;
        for(j=0;j<n;j++){       //Loop to insert in linked list according to available % slots
            x=a[j]%d;
            insert(s,a[j],x);
            siz[x]++;           //Storing size of each index
        }
        count=0;
        for(l=0;l<d;l++){       //this loop will sort each linked list
            if(s[l]==NULL)      //if list is empty at current index continue
                continue;
            int b[siz[l]+1];
            temp=s[l];
            for(j=0;j<siz[l];j++){
                b[j]=temp->num;
                temp=temp->next;
            }
            if(siz[l]>0)
                iSort(b,siz[l]);    //Sorting Each Linked list content
           for(j=0;j<siz[l];j++){
               a[count]=b[j];       //Getting PArtially Sorted array after combining each sorted list content
               count++;
           }

        }
    
   
}


int main(){
    int a[1000],i,n,d;
    printf("Enter number of FREE slots:\n");
    scanf("%d",&d);

    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter numbers:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);                   //This will store each number in a array
    }
    q8sort(a,n,d);                          //partially sorted array is returned in a
    printf("Partially Sorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);                  //Printing PArtially sorted array
    }
    printf("\n\n");
    printf("Sorted array is:\n");
    iSort(a,n);                              //Sorting Partially sorted array to fully sorted array using insertion Sort
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}