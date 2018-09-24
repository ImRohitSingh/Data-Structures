#define TRUE 1
#define FALSE 0

typedef struct BST
{
	struct BST *left;
	int data;
	struct BST *right;	
}*NODEPTR;

// function prototypes
int max(int a,int b); // to find the maximum between two number
void initTree(NODEPTR *);  // to intialize tree
void createBST(NODEPTR *); // to create BST
NODEPTR makeNode(int); // to create a node
int countNode(NODEPTR); // to cound number of nodes
int countLeaf(NODEPTR); // to cound number of leaf nodes
int treeHeight(NODEPTR);  // to find height of the tree
NODEPTR searchTree(NODEPTR,int); // to find a target
int delNodeBST(NODEPTR *,int); // to delete a node from the tree
int removeRoot(NODEPTR *); // remove the root

// function definitions
int max(int a,int b) // to find the maximum between two number
{
	return ((a>b)?a:b);
}
// to intialize tree
void initTree(NODEPTR *pTree)
{
	*pTree = NULL;	
}  

// to create BST
void createBST(NODEPTR *pTree)
{
	NODEPTR newNode, position;
	int finished, info;
	char choice;
	do
	{
		printf("\nEnter information...");
		scanf("%d",&info);
		newNode = makeNode(info);
		
		if(*pTree == NULL)
			*pTree = newNode;	
		else
		{
			finished = FALSE;
			position = *pTree;
			do
			{
				if(newNode->data < position->data)
					if(position->left == NULL)
					{
						position->left = newNode;
						finished = TRUE;
					}
					else
						position = position->left;
				else if(newNode->data > position->data)
					if(position->right == NULL)
					{
						position->right = newNode;
						finished = TRUE;
					}
					else
						position = position->right;
				else
					return;
			}
			while(!finished);
		}
		printf("\nDo you wish to continue? (Y/y for YES) ...");
		scanf(" %c",&choice);
	}
	while(choice=='y' || choice=='Y');
}

// to create a node 
NODEPTR makeNode(int info)
{
	NODEPTR newNode;
	newNode = (struct BST *)malloc(sizeof(struct BST));
	if(newNode == NULL)
	{
		printf("\nMEMORY EXHAUSTED!!\n");
		exit(1);
	}	
	newNode->data = info;
	newNode->left = newNode->right = NULL;
	return newNode;
} 

// to cound number of nodes
int countNode(NODEPTR pTree)
{
	if(!pTree)
		return 0;
	else
		return (countNode(pTree->left)+countNode(pTree->right)+1);
}

// to cound number of leaf nodes
int countLeaf(NODEPTR pTree)
{
	if(!pTree)
		return 0;
	else if(!(pTree->left) && !(pTree->right))
		return 1;
	else
		return (countLeaf(pTree->left)+countLeaf(pTree->right));
}

// to find height of the tree 
int treeHeight(NODEPTR pTree)
{
	if(!pTree)
		return 0;
	else
		return (max(treeHeight(pTree->left),treeHeight(pTree->right))+1);	
}  

// to find a target
NODEPTR searchTree(NODEPTR pRoot,int target)
{
	for(;pRoot!=NULL && pRoot->data!=target;)
		if(target < pRoot->data)
			pRoot = pRoot->left;
		else
			pRoot = pRoot->right;
	return pRoot;
} 

// to delete a node from the tree
int delNodeBST(NODEPTR *pTree,int target)
{
	if((*pTree == NULL) || ((*pTree)->data == target) )
		return removeRoot(pTree);
	else if ( target < (*pTree)->data)
		return delNodeBST(&((*pTree)->left),target);
	else
		return delNodeBST(&((*pTree)->right),target);
}

// remove the root
int removeRoot(NODEPTR *pTree)
{
	NODEPTR toDelete, parent;
	if(*pTree == NULL)
		return;
	toDelete = *pTree;
	if((*pTree)->left == NULL)
		*pTree = (*pTree)->right;
	else if((*pTree)->right == NULL)
		*pTree = (*pTree)->left;
	else
	{
		toDelete = (*pTree)->left; // find inorder predecessor
		parent = *pTree;
		while(!(toDelete->right))
		{
			parent = toDelete;
			toDelete = toDelete->right;
		}
		if(parent == *pTree)
			(*pTree)->left = toDelete->left;
		else
			parent->right = toDelete->left;
	}
	free(toDelete);
} 
