/* Implementation of a STACK using Singly Linked List (PUSH, POP both are constant time operations) */
#include<stdio.h>
#include<stdlib.h>
#include "stacklinkedlist.h"

int main(void)
{
	NODEPTR stack;  // holds the last node
	int choice,toPush,popped;  // declaring other variables
	initStack(&stack);  // function call to initialize stack
	do
	{
		printf("\n-------MENU-------\n1.PUSH\n2.POP\n3.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter information to push: ");
					scanf("%d",&toPush);
					if(push(&stack,toPush))  // function call to push 'toPush'
						printf("\n%d pushed successfully.\n",toPush);  
					else
						printf("\nMAIN MEMORY EXHAUSTED! Push operation unsuccessful...\n");
					break;
			case 2: if(pop(&stack,&popped))   // function call to pop 
						printf("\n%d popped successfully.\n",popped);
					else
						printf("\nSTACK EMPTY. Pop operation unsuccessful...\n");
					break;
			case 3: printf("\nDONE!\n");
					break;
			default: printf("\nInvalid choice. Re-enter please...\n");
					 break;
		}
	}
	while(choice!=3);
	return 0;
}



