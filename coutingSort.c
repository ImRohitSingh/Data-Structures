#include<stdio.h>
#include "integerSorting.h"

int main()
{
	int *a, n;
	n = 10;
	a = allocateSpace(n);  // function call to create space for an array
	printf("\nEnter elements:\n");
	a = populateArray(a,n);  // function call to populate an array
	printf("\n\nThe array: \n\n");
	displayArray(a,n);  // function call to display an array
	a = countingSort(a,n); // function call to perform Counting Sort
	printf("\n\nThe sorted array: \n\n");
	displayArray(a,n);  // function call to display an array
	return 0;
}
