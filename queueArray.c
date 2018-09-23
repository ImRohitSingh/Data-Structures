#include<stdio.h>
#include "queuearray.h"

/* Limitation: 
		(follow the operations)
			enqueue (10)
			enqueue (20)
			enqueue (30)
			dequeue
			dequeue
			dequeue
			enqueue (40)
			dequeue
			
			... At this point both ... empty and full conditions both are satisfied... */

int main()
{
	// declaring and initializing variables
	Q queue;
	int choice,toAppend,overflow,underflow,served;
 	initQueue(&queue);  // function call to initialize the queue
	do
	{
		printf("\n----------MENU-----------\n1.ENQUEUE\n2.DEQUEUE\n3.EXIT\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter element to append: ");
					scanf("%d",&toAppend);
					append(&queue,toAppend,&overflow);  // function call to append 'toAppend'
					if(!overflow)
						printf("\n%d appended successfully.\n",toAppend);
					else
						printf("\nQueue full.\n");
					break;
			case 2:	serve(&queue,&served,&underflow);  // function call to 'dequeue'
					if(!underflow)
						printf("\n%d served successfully.\n",served);
					else
						printf("\nQueue empty.\n");
					break;
			case 3: printf("\nDONE.\n");
					break;
			default: printf("\nRe-enter please...\n");
					 break;
		}
	}
	while(choice!=3);
	return 0;
}  



