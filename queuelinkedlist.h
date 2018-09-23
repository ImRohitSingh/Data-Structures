#define TRUE 1
#define FALSE 0

typedef struct queue
{
	int info;  // information of the node
	struct queue *next; // address of the next node
}*NODEPTR;

// function prototypes
void initQueue(NODEPTR *);  // to initialize queue
int enqueue(NODEPTR *,int);  // to append an informtation to the queue
int dequeue(NODEPTR *,int *);  // to serve an information out of the queue

// function definitions

// to initialize queue
void initQueue(NODEPTR *pQueue)
{
	*pQueue = NULL;	
}  

// to append an informtation to the queue
int enqueue(NODEPTR *pQueue,int toAppend)
// Post-condition: *pQueue points to the so-called last node
{
	NODEPTR newNode;  // node to append
	newNode = malloc(sizeof(struct queue));  // allocate space
	if(newNode == NULL)  // cannot allocate space for a new node
		return FALSE;
	newNode->info = toAppend;
	if(*pQueue == NULL)   // empty queue
		newNode->next = newNode;
	else if(*pQueue == (*pQueue)->next)  // only one node
	{
		newNode->next = *pQueue;
		(*pQueue)->next = newNode;
	}
	else  // more than one nodes
	{
		newNode->next = (*pQueue)->next;
		(*pQueue)->next = newNode;	
	}
	*pQueue = newNode;
	return TRUE;	
}  

// to serve an information out of the queue
int dequeue(NODEPTR *pQueue,int *served)
{
	NODEPTR delNode; // node to serve
	if(*pQueue == NULL) // empty queue
		return FALSE;
	if(*pQueue == (*pQueue)->next)  // only one node in the queue
	{
		delNode = *pQueue;
		initQueue(pQueue);  // function call to initialize queue
	}
	else  // more than one node in the queue
	{
		delNode = (*pQueue)->next;
		(*pQueue)->next = delNode->next;
	}
	*served = delNode->info;  // information that was served
	free(delNode);  // empty space for the served node
}
