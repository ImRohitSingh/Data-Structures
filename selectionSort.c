#include<stdio.h>
#include "integerSorting.h"

int main()
{
	int *a, n;
	n = 5;
	a = allocateSpace(n);  // function call to create space for an array
	printf("\nEnter elements:\n");
	a = populateArray(a,n);  // function call to populate an array
	printf("\n\nThe array: \n\n");
	displayArray(a,n);  // function call to display an array
	a = selectionSort(a,n); // function call to perform Selection Sort
	printf("\n\nThe sorted array: \n\n");
	displayArray(a,n);  // function call to display an array
	return 0;
}
