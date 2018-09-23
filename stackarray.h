#define MAXSTACK 5
#define TRUE 1
#define FALSE 0

typedef struct stack 
{
	int a[MAXSTACK];
	int top;
}S;


// function prototypes
void initStack(S *); // initializing the stack
void push(S *, int, int *); // push an integer to the stack
void pop(S *, int *, int *);  // pop an element out of the stack

// function definitions
// initializing the stack
void initStack(S *pStack)
{
	pStack->top=-1;
}

// push an integer to the stack
void push(S *pStack,int toPush,int *overflow)
{
	if(pStack->top==MAXSTACK-1)
		*overflow = TRUE;
	else
	{
		*overflow = FALSE;
		pStack->a[++(pStack->top)] = toPush;
	}
}

// pop an element out of the stack 
void pop(S *pStack,int *popped,int *underflow)
{
	if(pStack->top==-1)	
		*underflow = TRUE;
	else
	{
		*underflow = FALSE;
		*popped = pStack->a[(pStack->top)--];
	}
}   
