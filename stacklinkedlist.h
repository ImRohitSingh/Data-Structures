#define TRUE 1
#define FALSE 0

// stack declaration
typedef struct stack
{
	int info;
	struct stack *next;
	// a node of the stack contains two information
}*NODEPTR;

// function prototypes
void initStack(NODEPTR *);   // initialize the stack
int push(NODEPTR *,int); // to push information to the stack
int pop(NODEPTR *,int *); // to pop an information out of the stack

// function definition

// to initalize the stack
void initStack(NODEPTR *pStack)
{
	*pStack = NULL;
}

// to push 'toPush' to the stack
int push(NODEPTR *pStack,int toPush)
{
	NODEPTR newNode; // node to push
	newNode = malloc(sizeof(struct stack));
	if(newNode == NULL)  // cannot create space
		return FALSE;
	newNode->info = toPush;
	if(*pStack == NULL)  // stack is empty
		newNode->next = NULL;
	else
		newNode->next = *pStack;
	*pStack = newNode;
	return TRUE;	
}

// to pop an information out of the stack
int pop(NODEPTR *pStack,int *popped)
{
	NODEPTR delNode; // node to remove
	if(*pStack == NULL) // empty stack
		return FALSE;
	delNode = *pStack;
	*popped = delNode->info;
	if(delNode->next == NULL) // contains only one node
		initStack(pStack); 
	else
		*pStack = delNode->next;  // make the next node as the first
	free(delNode); // clear space	
}  
