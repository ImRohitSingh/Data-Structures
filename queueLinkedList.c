/* Queue implemented with the help of a Circular Linked List (Enqueue and Dequeue are constant time operation) */
#include <stdio.h>
#include <stdlib.h>
#include "queuelinkedlist.h"

int main(void)
{
	NODEPTR queue;  // pointer to the starting node of the queue
	char choice;
	int toAppend,served;  // other variables
	initQueue(&queue);  // function call to initialize queue
	do
	{
		printf("\n-------MENU-------\nA.Enqueue\nB.Serve\nC.Exit\nEnter choice:");
		scanf(" %c",&choice);
		switch(choice)
		{
			case 'A': printf("\nEnter information...");
					  scanf("%d",&toAppend);
					  if(enqueue(&queue,toAppend))
					  	printf("\n%d appended successfully.\n",toAppend);
					  else
					  	printf("\nSYSTEM MEMORY EXHAUSTED. Enqueue operation unsuccessful...\n");
					  break;
			case 'B': if(dequeue(&queue,&served))
					  	printf("\n%d served successfully.\n",served);
					  else
					  	printf("\nQUEUE EMPTY. Dequeue operation unsuccessful...\n");
					  break;
			case 'C': printf("\nDONE!\n");
					  break;
			default: printf("\nInvalid choice. Re-enter please...\n");
					 break;
		}
	}
	while(choice!='C');
	return 0;
}

