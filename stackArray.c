#include<stdio.h>
#include "stackarray.h"

int main()
{
	// declaring and initializing variables
	S stack;
	int choice,toPush,overflow,underflow,popped;
 	initStack(&stack);  // function call to initialize the stack
	do
	{
		printf("\n----------MENU-----------\n1.PUSH\n2.POP\n3.EXIT\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter element to push: ");
					scanf("%d",&toPush);
					push(&stack,toPush,&overflow);  // function call to push 'toPush'
					if(!overflow)
						printf("\n%d pushed successfully.\n",toPush);
					else
						printf("\nStack full.\n");
					break;
			case 2:	pop(&stack,&popped,&underflow);  // function call to 'pop'
					if(!underflow)
						printf("\n%d popped successfully.\n",popped);
					else
						printf("\nStack empty.\n");
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



