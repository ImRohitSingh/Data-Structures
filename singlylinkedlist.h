typedef struct node
{
	int info;
	struct node *next;
}*NODEPTR;

// function prototypes
void initList(NODEPTR *); // initialize list
void createList(NODEPTR *); // create list
void displayList(NODEPTR ); // display list
int countNode(NODEPTR); // count number of nodes in the list
void concatLists(NODEPTR *,NODEPTR *); // concate two lists
void insertFirst(NODEPTR *,int); // to insert a data at first node
void insertAfter(NODEPTR *,int); // insert a node just after the node pointed to by this pointer
void insertLast(NODEPTR *,int);  // insert a data as the last node
void insertPos(NODEPTR *,int,int); // insert data at a given position
void insertInfo(NODEPTR *,int,int);  // insert a data after a given data
void deleteFirst(NODEPTR *);  // delete the first node
void deleteAfter(NODEPTR *); // delete the node just after the node pointed to by this pointer
void deleteLast(NODEPTR *); // delete the last node
void deletePos(NODEPTR *,int);  // delete data from a given position
void deleteInfo(NODEPTR *,int); // delete all occurences of a given data
void reverseList(NODEPTR *);  // to reverse the list

// function definitions
// initialize list
void initList(NODEPTR *pList)
{
	*pList = NULL;
}

// create list
void createList(NODEPTR *pList)
{
	NODEPTR newNode,prevNode;
	char choice;
	do
	{
		newNode = malloc(sizeof(struct node));
		if(newNode == NULL)
		{
			printf("\nSYSTEM MEMORY EXHAUSTED. \n");
			return;
		}
		
		printf("\nEnter information: ");	
		scanf("%d",&newNode->info);
		newNode->next = NULL;
		
		if(*pList == NULL) 
			*pList = newNode; // first node
		else
			prevNode->next = newNode; // remove NULL content
		
		printf("\n Press Y / y to continue...\n");
		scanf(" %c",&choice);
		prevNode=newNode; // holds the last node created
	}
	while(choice=='Y' || choice=='y');	
}

// display list
void displayList(NODEPTR pList)
{
	if(pList == NULL)
	{
		printf("\nLIST EMPTY!!!\n");
		return;
	}
	printf("\nThe list: \n");
	for(;pList->next != NULL;pList = pList->next)
		printf("%d->",pList->info);
	printf("%d\n",pList->info);		
}

// count number of nodes in the list
int countNode(NODEPTR pList)
{
	int count=0;
	for(;pList!=NULL;pList = pList->next,++count)
		;
	return count;
}

// concate two lists
void concatLists(NODEPTR *list1,NODEPTR *list2)
{
	NODEPTR temp;
	if(*list1 == NULL)
	{
		*list1 = *list2;
		return;
	}
	else if(*list2 == NULL)
		return;
	else
	{
		for(temp = *list1; temp->next!=NULL; temp = temp->next)
			;
		temp->next = *list2;		
	}
}

// to insert a data at first node
void insertFirst(NODEPTR *pList,int data)
{
	NODEPTR newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("\nMEMORY EXHAUSTED. Cannot continue...\n");
		exit(1);
	}
	newNode->info = data;
	newNode->next = *pList;
	*pList = newNode;
}

// insert a node just after the node pointed to by this pointer
void insertAfter(NODEPTR *pList,int data)
{
	NODEPTR newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("\nMEMORY EXHAUSTED. Cannot continue...\n");
		exit(1);
	}
	newNode->info = data;
	newNode->next = (*pList)->next;
	(*pList)->next = newNode;
}

// insert a data as the last node
void insertLast(NODEPTR *pList,int data)
{
	NODEPTR newNode, temp;
	if(*pList == NULL)
		insertFirst(pList,data);
	else
	{
		for(temp = *pList; temp->next!=NULL; temp = temp->next)
			;
		insertAfter(&temp,data);
	}
}

// insert data at a given position
void insertPos(NODEPTR *pList,int pos,int data)
{
	NODEPTR temp;
	int i;
	//temp = *pList;
	if( (pos < 1) || (pos > countNode(*pList)+1) )
	{
		printf("\n\nINVALID POSITION!\n\n");
		exit(1);
	}
	if(pos==1)
		insertFirst(pList,data);
	else
	{
		for(temp = *pList, i = 1; i<pos-1; temp = temp->next )
			++i;
		insertAfter(&temp,data);	
	}
}

// insert a data after a given data
void insertInfo(NODEPTR *pList,int search,int data)
{
	NODEPTR temp;
	int status;
	status = 0; // to check if a match is found at all
	for(temp = *pList; temp!=NULL; temp = temp->next)
	{
		if( temp->info == search)
		{
			status = 1;
			insertAfter(&temp,data);
			if(temp->info == data) // to avoid infinite loop for same 'search' and 'data'
				temp = temp->next;	
		}	
	}
	if(!status)
		printf("\n\nNO MATCH FOUND!\n\n");	
}  

// delete the first node
void deleteFirst(NODEPTR *pList)
{
	NODEPTR delNode;
	if(*pList == NULL)
	{
		printf("\nLIST EMPTY.\n");
		return;
	}
	delNode = *pList;
	*pList = delNode->next;
	free(delNode);	
} 

// delete the node just after the node pointed to by this pointer
void deleteAfter(NODEPTR *pList)
{
	NODEPTR delNode;
	delNode = (*pList)->next;
	(*pList)->next = delNode->next;
	free(delNode);
}

// delete the last node
void deleteLast(NODEPTR *pList) 
{
	NODEPTR temp, delNode;
	if(*pList == NULL) // empty list
	{
		printf("\nLIST EMPTY.\n");
		return;
	}
	if((*pList)->next == NULL)
		deleteFirst(pList);
	else
	{
		temp = *pList;
		
		for(; temp->next != NULL ; temp = temp->next)
			delNode = temp;
		deleteAfter(&delNode);
	}
}

// delete data from a given position
void deletePos(NODEPTR *pList,int pos) 
{
	NODEPTR delNode;
	int i;
	if((pos < 1) || (pos > countNode(*pList)) )
	{
		printf("\n\nINVALID POSITION!\n\n");
		exit(1);
	}
	if(pos==1)
		deleteFirst(pList);
	else
	{
		for(delNode = *pList, i = 1; i < pos - 1; delNode = delNode ->next)
			;
		deleteAfter(&delNode);
	}
}

// delete all occurences of a given data
void deleteInfo(NODEPTR *pList,int data)
{
	NODEPTR temp,prevNode;
	if(*pList == NULL)
	{
		printf("\nINSUFFICIENT NUMBER OF NODES!\n");
		return;
	}
	for(temp = *pList, prevNode = NULL; temp!=NULL && temp->info!=data ;prevNode = temp, temp = temp->next)
		;
	if(temp == NULL)
	{
		printf("\n\nNO MATCH FOUND!\n\n");
		return;
	}
	if(prevNode == NULL)
		deleteFirst(pList);
	else
		deleteAfter(&prevNode);
			//*pList = temp;
}

void reverseList(NODEPTR *pList)  // to reverse the list
{
	NODEPTR p, q, temp;
	p = q = temp = NULL;
	if(*pList == NULL)
		return;
	for(p = *pList; p != NULL; p=temp )
	{
		temp = p->next;
		p->next = q;
		q=p;
	}
	*pList = q;
}
