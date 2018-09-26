#include <stdio.h>
#include <stdlib.h>

#include "circularLinkedList.h"

int main(void)
{
	NODEPTR list,list2;
	int choice, data, target, flag;
	
	initList(&list);  // function call to initialize list
	createList(&list);  // function call to create list
	do
	{
		printf("\n1.Display\n2.Count Nodes\n3.Concatinate Lists\n4.Insert First\n5.Insert Last\n6.Insert WRT Information\n");
		printf("7.Delete First\n8.Delete Last\n9.Delete WRT Information\n10.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: displayList(list); // function call to display list
					break;
			case 2: printf("\nThere are %d node(s) in the list.\n",countNode(list)); // function call to count number of nodes in a list
					break;
			case 3: initList(&list2);  // function call to initialize list
					createList(&list2);  // function call to create list
					concatList(&list,&list2); // function call to concatinate list
					break;
			case 4: printf("\nEnter information...\n");
					scanf("%d",&data);
					insertFirst(&list,data); // function call to insert a node at the begining
					break;
			case 5: printf("\nEnter information...\n");
					scanf("%d",&data);
					insertLast(&list,data);  // function call to insert a node at the end
					break;
			case 6: printf("\nEnter target...\n");
					scanf("%d",&target);
					printf("\nEnter data...\n");
					scanf("%d",&data);
					insertAfterInfo(&list,target,data);  //  function call to insert node(s) at the end of all the occurences of a given target
					break;
			case 7: deleteFirst(&list);   // function call to delete the first node
					break;
			case 8: deleteLast(&list); // function call delete the last node
					break;
			case 9: printf("\nEnter information...\n");
					scanf("%d",&target);
					printf("\n%d deletion(s) made.\n",deleteInfo(&list,target));  // function call to delete all occurences of target
					break;
			case 10: printf("\nDONE!\n");
					 break;
			default: printf("\n Invalid choice. Re-enter please...\n");
		}	
	}
	while(choice!=10);
	return 0;
}
