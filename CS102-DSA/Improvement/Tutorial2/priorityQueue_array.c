#include <stdio.h>
#include <limits.h> 
#include <malloc.h>

#define CAPACITY 1000


// Structure for the elements in the 
// priority queue 
struct item { 
    int value; 
    int priority; 
};

//Structure for the priority queue
struct PriorityQueue{
    struct item* pr;
    int size;
}; 

struct PriorityQueue* createPQ()
{
    struct PriorityQueue* pq = (struct PriorityQueue*)
                                    malloc(sizeof(struct PriorityQueue));
    pq->pr = (struct item*)malloc(CAPACITY*sizeof(struct item));
    pq->size = -1;

    return pq;
}
int isFull(struct PriorityQueue* pq) 
{ 
	return (pq->size == CAPACITY); 
} 

int isEmpty(struct PriorityQueue* pq) 
{ 
	return (pq->size == -1);
}
 
void enqueue(struct PriorityQueue* pq, int value, int priority) 
{ 
    if (isFull(pq)) 
		return;

    pq->size++; 

    pq->pr[pq->size].value = value; 
    pq->pr[pq->size].priority = priority; 
} 

// Find the position of the element 
// with highest priority 
int peek(struct PriorityQueue* pq) 
{
    if (isEmpty(pq)) 
		return INT_MIN;

    int highestPriority = INT_MIN; 
    int ind = -1; 
  
    // Check for the element with 
    // highest priority 
    for (int i = 0; i <= pq->size; i++) { 
  
        // If priority is same choose 
        // the element with the 
        // highest value 
        if (highestPriority == pq->pr[i].priority*(-1) 
                && ind > -1 && pq->pr[ind].value > pq->pr[i].value) 
        { 
            highestPriority = pq->pr[i].priority*(-1); 
            ind = i; 
        } 
        else if (highestPriority < pq->pr[i].priority*(-1)) 
        { 
            highestPriority = pq->pr[i].priority*(-1); 
            ind = i; 
        } 
    } 

    return ind; 
} 
  
// Function to remove the element with 
// the highest priority 
void dequeue(struct PriorityQueue* pq) 
{ 
    if (isEmpty(pq)) 
		return;

    int ind = peek(pq); 
  
    // Shift the element one index before 
    // from the postion of the element 
    // with highest priortity is found 
    for (int i = ind; i < pq->size; i++) 
    { 
        pq->pr[i] = pq->pr[i + 1]; 
    } 

    pq->size--; 
}
int main() 
{ 
    struct PriorityQueue* pq = createPQ();

    enqueue(pq, 3, 4);  
    enqueue(pq, 7, 1); 
    enqueue(pq, 8, 2);
    enqueue(pq, 9, 3); 

    int ind = peek(pq); 
  
    printf("%d\n", pq->pr[ind].value);
  
    dequeue(pq); 

    ind = peek(pq); 
    printf("%d\n", pq->pr[ind].value);

    return 0; 
} 