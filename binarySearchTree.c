#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
	NODEPTR tree;
	int choice, search, target;
	initTree(&tree); // function call to initialize tree
	createBST(&tree); // function call to create BST
	do
	{
		printf("\n------MENU------\n1.Count Nodes\n2.Count Leaf\n3.Find Height\n4.Search\n5.Delete\n6.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nThere are %d node(s) in the tree.\n",countNode(tree));  // function call to count the number of nodes
					break;
			case 2: printf("\nThere are %d leaf node(s) in the tree.\n",countLeaf(tree));  // function call to count the number of nodes
					break;
			case 3: printf("\nHeight of the tree = %d\n",treeHeight(tree));  // function call to count the number of nodes
					break;
			case 4: printf("\nEnter target...\n");
					scanf("%d",&search);
					if(!searchTree(tree,search)) // function call to search the tree for a given target
						printf("\nNo match found.\n");
					else
						printf("\nMatch found.\n");
					break;
			case 5: printf("\nEnter target to remove...\n");
					scanf("%d",&target);
					delNodeBST(&tree,target);  // function call to delete a target from the tree
					break;
			case 6: break;
			default: printf("\n\nINVALID CHOICE!! Re-enter please...\n\n");
					 break;
		}
	}
	while(choice!=6);
	return 0;
	
}
