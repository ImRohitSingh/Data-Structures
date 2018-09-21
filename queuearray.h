#define MAXQUEUE 4
#define TRUE 1
#define FALSE 0

typedef struct queue
{
	int a[MAXQUEUE];
	int front;
	int rear;
}Q;


// function prototypes
void initQueue(Q *); // initializing the queue
void append(Q *, int, int *); // enqueue an integer to the queue
void serve(Q *, int *, int *);  // dequeue an element out of the queue

// function definitions
// initializing the queue
void initQueue(Q *pQueue)
{
	pQueue->front = pQueue->rear = -1;
}

// enqueue an integer to the queue
void append(Q *pQueue,int toAppend,int *overflow)
{
	if(pQueue->rear==MAXQUEUE-1)
		*overflow = TRUE;
	else
	{
		*overflow = FALSE;
		pQueue->a[++(pQueue->rear)] = toAppend;
	}
}

// dequeue an element out of the queue
void serve(Q *pQueue,int *served,int *underflow)
{
	if(pQueue->front==pQueue->rear)	
		*underflow = TRUE;
	else
	{
		*underflow = FALSE;
		*served = pQueue->a[++(pQueue->front)];
	}
}  
