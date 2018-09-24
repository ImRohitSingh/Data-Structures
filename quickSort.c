#include<stdio.h>
#include<time.h>
#include "integerSorting.h"

int main()
{
	FILE *fin, *fout;  // file pointers
	int *a, n, i;
	n=500;  // number of elements
	
	fin = fopen("To_Quick_Sort.txt","w+");
	srand(time(NULL));  // used to generate distinct numbers at each execution of this program
	for(i=0; i<n; ++i)
		fprintf(fin," %d ",rand()%1000+1);  // populate file with random numbers between 0 - 1000
	rewind(fin);  // take fin to the start of the file
	
	a = allocateSpace(n); // function call to create space for an array
	for(i=0;i<n;++i)
		fscanf(fin,"%d",&a[i]);  // store file content to the array
	
	a = quickSort(a,0,n-1);  // function call to perform Quick Sort
	
	fout = fopen("Sorted_Using_Quick.txt","w+");
	for(i=0; i<n; ++i)
		fprintf(fout," %d ",a[i]);  // populate file with sorted a[i] elements
		
	return 0;	
}
