#include<stdio.h>
#include "integerSorting.h"

int main()
{
	int *a, n;
	n = 13;
	a = allocateSpace(n);  // function call to create space for an array
	printf("\nEnter elements:\n");
	a = populateArray(a,n);  // function call to populate an array
	printf("\n\nThe array: \n\n");
	displayArray(a,n);  // function call to display an array
	a = mergeSort(a,0,n-1); // function call to perform Shell Sort
	printf("\n\nThe sorted array: \n\n");
	displayArray(a,n);  // function call to display an array
	return 0;
}
