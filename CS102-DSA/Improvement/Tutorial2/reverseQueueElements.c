#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isStackEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
    if (isStackFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack)
{
    if (isStackEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
int peek(struct Stack* stack)
{
    if (isStackEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}


//A structure to represent Queue
struct Queue { 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 

struct Queue* createQueue(unsigned capacity) 
{ 
	struct Queue* queue = (struct Queue*)malloc( 
		sizeof(struct Queue)); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 

	queue->rear = capacity - 1; 
	queue->array = (int*)malloc( 
		queue->capacity * sizeof(int)); 
	return queue; 
} 

int isQueueFull(struct Queue* queue) 
{ 
	return (queue->size == queue->capacity); 
} 

int isQueueEmpty(struct Queue* queue) 
{ 
	return (queue->size == 0); 
} 

void enqueue(struct Queue* queue, int item) 
{ 
	if (isQueueFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) 
				% queue->capacity; 
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	printf("%d enqueued to queue\n", item); 
} 

int dequeue(struct Queue* queue) 
{ 
	if (isQueueEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) 
				% queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
} 

int front(struct Queue* queue) 
{ 
	if (isQueueEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
} 

int rear(struct Queue* queue) 
{ 
	if (isQueueEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
}

void reverseQueueFirstKElements(int k, struct Queue* Queue)
{
    if (isQueueEmpty(Queue) == true || k > Queue->size)
        return;
    if (k <= 0)
        return;
 
    struct Stack* stack = createStack(100);
 
    for (int i = 0; i < k; i++) {
        push(stack, front(Queue));
        dequeue(Queue);
    }
 
    while (!isStackEmpty(stack)) {
        enqueue(Queue, peek(stack));
        pop(stack);
    }
 
    for (int i = 0; i < Queue->size - k; i++) {
        enqueue(Queue, front(Queue));
        dequeue(Queue);
    }
}

void Print(struct Queue* Queue)
{
    while (!isQueueEmpty(Queue)) {
        printf("%d ", front(Queue));
        dequeue(Queue);
    }
}

int main()
{
    struct Queue* queue = createQueue(100);

    enqueue(queue, 10); 
	enqueue(queue, 20); 
	enqueue(queue, 30); 
	enqueue(queue, 40);
    enqueue(queue, 50); 
	enqueue(queue, 60); 
	enqueue(queue, 70); 
	enqueue(queue, 80);
    enqueue(queue, 90); 
	enqueue(queue, 100);
 
    int k = 5;
    reverseQueueFirstKElements(k, queue);
    Print(queue);

    return 0;
}