// root pointer points to the so called last node
typedef struct node
{
	int info;
	struct node *next;
}*NODEPTR;

// function prototypes
void initList(NODEPTR *); // to initalize list
void createList(NODEPTR *); // to create list
void displayList(NODEPTR); // to display list
int countNode(NODEPTR); // to count numer of nodes
void concatList(NODEPTR *,NODEPTR *); // to concatinate two lists
void insertFirst(NODEPTR *,int); // to insert a node at the begining
void insertLast(NODEPTR *,int); // to insert a node at the end
void insertAfter(NODEPTR,int); // to insert a node just after the node pointed to by the passed reference
void insertAfterInfo(NODEPTR *,int,int); // to insert a node after a match is found just after a given target
void deleteFirst(NODEPTR *);  // to delete the first node
void deleteLast(NODEPTR *); // to delete the last node
void deleteAfter(NODEPTR);  // to delete a node just after the node pointed to by the passed reference
int deleteInfo(NODEPTR *,int); // to delete all occurences of a given information

// function definitions
// to initalize list
void initList(NODEPTR *pList)
{
	*pList = NULL;
}

// to create list
void createList(NODEPTR *pList)
{
	NODEPTR newNode;
	char choice;
	do
	{
		newNode =  (struct node *)malloc(sizeof(struct node));
		if(newNode == NULL)
		{
			printf("\nMEMORY EXHAUSTED!!\n");
			exit(1);
		}
		
		printf("\nEnter information...  ");
		scanf("%d",&newNode->info);
		 
		if(*pList == NULL)
			newNode->next = newNode;
		else
		{
			newNode->next = (*pList)->next;
			(*pList)->next = newNode;
		}
		printf("\nDo you wish to continue? (Y/y for yes) ");
		scanf(" %c",&choice);
		*pList = newNode;
		printf("%d\n",(*pList)->info);
	}
	while(choice =='y' || choice =='Y');
 } 
 
// to display list
void displayList(NODEPTR pList) 
{
	NODEPTR temp;
	if(pList == NULL)
	{
		printf("\nNothing to display.\n");
		return;
	}
	printf("\nThe List:\n");
	temp = pList->next;
	for(; temp != pList; temp = temp->next)
		printf("%d->",temp->info);
	printf("%d\n",pList->info);
}

// to count numer of nodes
int countNode(NODEPTR pList)
{
	NODEPTR temp;
	int count;
	if(pList == NULL)
		return 0;
	count = 1;
	for(temp = pList; temp->next != pList ; temp = temp->next)
		++count;
	return count;
} 

// to concatinate two lists
void concatList(NODEPTR *pList1,NODEPTR *pList2) 
{
	NODEPTR temp;
	if(*pList2 == NULL)
		return;
	if(*pList1 == NULL)
		*pList1 = *pList2;
	else
	{
		temp = (*pList2)->next;
		(*pList2)->next = (*pList1)->next;
		(*pList1)->next = temp;
		*pList1 = *pList2;
	}
}

// to insert a node at the begining
void insertFirst(NODEPTR *pList,int data)
{
	NODEPTR newNode;
	newNode =  (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("\nMEMORY EXHAUSTED!!\n");
		exit(1);
	}
	newNode->info = data;
	if(*pList == NULL)
	{
		newNode->next = newNode;
		*pList = newNode;
	}
	else
	{
		newNode->next = (*pList)->next;
		(*pList)->next = newNode;
	}
}

// to insert a node at the last
void insertLast(NODEPTR *pList,int data)
{
	NODEPTR newNode;
	if(*pList == NULL)
		insertFirst(pList,data);
	else
	{
		newNode =  (struct node *)malloc(sizeof(struct node));
		if(newNode == NULL)
		{
			printf("\nMEMORY EXHAUSTED!!\n");
			exit(1);
		}
		newNode->info = data;
		newNode->next = (*pList)->next;
		(*pList)->next = newNode;
		*pList = newNode;
	}
} 

// to insert a node just after the node pointed to by the passed reference
void insertAfter(NODEPTR pList,int data)
{
	NODEPTR newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("\nMEMORY EXHAUSTED!!\n");
		exit(1);
	}
	newNode->info = data;	
	newNode->next = pList->next;
	pList->next = newNode;
} 

// to insert a node after a match is found just after a given target
void insertAfterInfo(NODEPTR *pList,int target,int data)
{
	NODEPTR  p, temp;
	int status = 0; //  not inserted
	if(*pList == NULL)
	{
		printf("\nLIST EMPTY!!\n");
		return;
	}
	p = temp = *pList;
	do
	{
		if(p->info == target)
		{
			if(p == *pList) // match found at so-called last node
			{
				insertLast(pList,data);  // root pointer will change
				if(p->info == data) // avoid redundant entries (infinite loop)
					p = p->next;
			}
			else  // match at any other node
			{
				insertAfter(p,data);
				if(p->info == data) // avoid redundant entries (infinite loop)
					p = p->next;
			}
			status += 1; // change status if at least one match is found
		}
		p = p->next;
	}
	while(p!=temp);
	if(!status)
		printf("\nNo match found!\n");
	else
		printf("\n%d insertion(s) made.\n",status);
} 

// to delete the first node
void deleteFirst(NODEPTR *pList)
{
	NODEPTR delNode;
	if(*pList == NULL)
	{
		printf("\nLIST EMPTY.\n");
		return;	
	}	
	delNode = (*pList)->next;
	if( delNode == delNode->next) // only one node
		initList(pList);
	else
		(*pList)->next = delNode->next;
	free(delNode);
}


// to delete the last node
void deleteLast(NODEPTR *pList)
{
	NODEPTR delNode;
	if(*pList == NULL)
	{
		printf("\nLIST EMPTY.\n");
		return;	
	}
	delNode = *pList;
	if(delNode == delNode->next)
		deleteFirst(pList);
	else
	{
		for( ; delNode->next != *pList; delNode = delNode->next)
			;
		deleteAfter(delNode);
		*pList = delNode;
	}
}

// to delete a node just after the node pointed to by the passed reference
void deleteAfter(NODEPTR pList)
{
	NODEPTR delNode;
	delNode = pList->next;
	pList->next = delNode->next;
	free(delNode);	
}  

// to delete all occurences of a given information
int deleteInfo(NODEPTR *pList,int target)
{
	NODEPTR delNode, temp, prevNode, toDel;
	int status;
	if(*pList == NULL)
	{
		printf("\nLIST EMPTY.\n");
		return;	
	}
	status = 0;
	delNode = temp = *pList;
	prevNode = NULL;
	do
	{
		if(delNode->info == target)
		{
			if(prevNode == NULL)  // match at beginning
			{
				//delNode = delNode->next;
				deleteLast(pList);
				if(*pList == NULL)
					return;
				prevNode = temp = *pList;
				delNode = prevNode->next;
			}
			else // match elsewhere
			{
				toDel = prevNode;  // delete after toDel
				prevNode = delNode;
				delNode = delNode->next;
				deleteAfter(toDel);
			}
			status += 1;
			
		}
		else // no match
		{
			prevNode = delNode;
			delNode = delNode->next;
		}
	}
	while(delNode != temp);
	
	if((*pList)->info == target)
	{
		deleteLast(pList);
		++status;
	}
	return status;
}
	

