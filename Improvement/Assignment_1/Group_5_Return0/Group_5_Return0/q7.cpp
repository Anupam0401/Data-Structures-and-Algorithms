//TIme Complexity-> O(d*n*logn)
//Space COmplexity -> O(n*logn)
//Compile With g++ compiler
#include <stdio.h>
#include <stdlib.h>

struct Node
{  int num;
    struct Node* next;
};

//FUnction to calculate number of digits in a number
int digit(int n){
    int count=0;
    while(n!=0)  
   {  
       n=n/10;  
       count++;  
   }
   return count;
}

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

//function to merge two sorted array
void merge(int x[], int left, int mid, int right)
{
    int i, j, k,a = mid - left + 1,b = right - mid, aleft[a], aright[b];

    //initialising left and right array with data of x array
    for (i = 0; i < a; i++)
        aleft[i] = x[left + i];
    for (j = 0; j < b; j++)
        aright[j] = x[mid + 1 + j];
 
    i = 0; 
    j = 0; 
    k = left; 
    // Merging both left right arrays into X array in order
    while (i < a && j < b) {
        if (aleft[i] <= aright[j]) {
            x[k] = aleft[i];
            i++;
        }
        else {
            x[k] = aright[j];
            j++;
        }
        k++;
    }
    //if any element left in left or right array put back in X
    while (i < a) {
        x[k] =aleft[i];
        i++; k++;
    }
    while (j < b) {
        x[k] = aright[j];
        j++; k++;
    }
}

//function to mergesort
void mergeSort(int x[], int left, int right)
{
    if (left < right) {
        int mid = left + (right-left)/2;// calculating mid element
        mergeSort(x, left, mid);        //sorting left part
        mergeSort(x, mid + 1, right);   //sorting right part of array
        merge(x, left, mid, right);     //merging both sorted parts of array
    }
}

void q7sort(int a[],int n){
    int max=-99999,i,j,k,l,d,x,y,count;
    //Function to get max number which have maximum digits
    for(i=0;i<n;i++){
        if(max<a[i])
            max=a[i];       //storing max
    }
    d=digit(max);           //Number of  digits in max element


    for(i=0,k=10;i<d;k=k*10,i++){       //this loop will run max digit number of times
        struct Node* s[10]={0};
        int siz[10]={0};
        struct Node* temp;
        for(j=0;j<n;j++){               //this loop will insert each digit in its appropriate index Linked list
            x=a[j]%k;
            y=a[j]%(k/10);
            x=x-y;
            x=x/(k/10);
            insert(s,a[j],x);           //Inserting digit at appropriate postion
            siz[x]++;                   //Storing Size of each index
            
        }
        count=0;
        for(l=0;l<10;l++){              //this loop will sort each linked list from (0,2,3 to ..., 10)
            if(s[l]==NULL)              //if list is empty at current index continue
                continue;
            int b[siz[l]+1];
            temp=s[l];
            //printf(" %d",(s[l])->num);

            for(j=0;j<siz[l];j++){      //Getting Data of linked list to apply merge sort via array
                b[j]=temp->num;
                temp=temp->next;
            }
            if(siz[l]>=2)
                mergeSort(b,0,siz[l]-1);    //Call to Sort data
           for(j=0;j<siz[l];j++){
               a[count]=b[j];               //Writing back the partially sorted data in array
               count++;
           }

        }
    }
   
}


int main(){
    int a[1000],i,n;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter numbers:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);              //This will store each number in a array
    }
    q7sort(a,n);                        //Function call to apply Logic on array
    printf("Sorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);             //Printing Final answer
    }
    printf("\n");
    return 0;
}