#include<stdio.h>
#include<stdlib.h>
#include "singlylinkedlist.h"

int main()
{
	NODEPTR list,list2;  // 'list' holds the initial node
	int choice, data, pos, search; // declaring other variables
	
	
	initList(&list);  // function call to initialize list
	createList(&list);  // function call to create list
	do
	{
		printf("\n---------MENU---------\n1.Display List\n2.Count Nodes\n3.Concat List\n4.Insert First\n5.Insert Last\n");
		printf("6.Insert WRT Position\n7.Insert WRT Information\n");
		printf("8.Delete First\n9.Delete Last\n10.Delete WRT Postition\n");
		printf("11.Delete WRT Information\n12.Reverse the list\n13.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: displayList(list); // function call to display list
					break;
			case 2: printf("\nThere are %d number of node(s) in the list.\n",countNode(list));  // function call to count number of nodes in the list
					break;
			case 3: initList(&list2);  // function call to initialize list
					createList(&list2);  // function call to create list
					concatLists(&list,&list2); // function call to concat lists
					break;
			case 4: printf("\nEnter information to insert...");
					scanf("%d",&data);
					insertFirst(&list,data); // function call to insert at first
					break;
			case 5: printf("\nEnter information to insert...");
					scanf("%d",&data);
					insertLast(&list,data); // function call to insert at last
					break;
			case 6: printf("\nEnter position to insert...");
					scanf("%d",&pos);
					printf("\nEnter information to insert...");
					scanf("%d",&data);
					insertPos(&list,pos,data); // function call to insert at last
					break;
			case 7: printf("\nEnter information after which you want to insert...");
					scanf("%d",&search);
					printf("\nEnter information to insert...");
					scanf("%d",&data);
					insertInfo(&list,search,data); // function call to insert at last
					break;
			case 8: deleteFirst(&list);
					break;
			case 9:	deleteLast(&list);
					break;	
			case 10: printf("\nEnter position to delete...");
					 scanf("%d",&pos);
					 deletePos(&list,pos);
					 break;
			case 11: printf("\nEnter information to delete...");
					 scanf("%d",&data);
					 deleteInfo(&list,data);
					 break;
			case 12: reverseList(&list);
					 break;
			case 13: printf("\nDONE!\n");
					 break;
			default: printf("\nInvalid choice. Re-enter please...\n");
					 break;	
		}
	}
	while(choice!=13);
	return 0;
}


