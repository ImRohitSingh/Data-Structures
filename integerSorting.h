#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// function prototypes
int* allocateSpace(int);  // to create space for an array
int* allocateSpaceInit(int);  // to create space for an array and initialize it with 0's
int* populateArray(int *,int);  // to populate an array
void displayArray(int *,int);  // to display an array
int* bubbleSort(int *,int);  // to perform Bubble Sort
int* bubbleSortAdaptive(int *,int);  // to perform Bubble Sort (an efficient version in the best case)
int* selectionSort(int *,int);  // to perform Selection Sort
int* insertionSort(int *,int);  // to perform Insertion Sort
int* shellSort(int *,int); // to perform Shell Sort
int* sortInterval(int *,int,int,int);  // to perform Insertion Sort on the chosen interval (refer Shell sort)
int* mergeSort(int *,int,int);  // to perform Merge Sort (divide)
int* merge(int *,int,int,int);  // to merge the subsequent divisions (conquer)
int* mergeEfficient(int *,int,int,int);  // to merge the subsequent divisions (conquer) (Efficient version)
int* quickSort(int *,int,int);  // to perform Quick Sort (conquer)
int* partitionHoare(int *,int,int,int *);   // to perform partion using Hoare partition
int* partitionLomuto(int *,int,int,int *); // to perform partion using Lomuto partition
int findMax(int *,int);  // to find the maximum from an array
int* countingSort(int *,int); // to perform Counting Sort

// function definitions
int* allocateSpace(int n)
// to create space for an array
{
	return (int *)malloc(n*sizeof(int));
}

int* allocateSpaceInit(int n)  
// to create space for an array and initialize it with 0's
{
	return (int *)calloc(n,sizeof(int));
}

int* populateArray(int *a,int n)
// to populate an array
{
	int i;
	for(i = 0; i < n; ++i)
	{
		printf("\nElement %d : ",i+1);
		scanf("%d",&a[i]);
	}
	return a;
}

void displayArray(int *a,int n)  
// to display an array
{
	int i;
	for( i = 0; i < n; ++i)
		if(i==0)
			printf("\n[%d",a[i]);
		else if(i == n-1)
			printf("%d]\n\n",a[i]);
		else
			printf(" %d ",a[i]);
}

int *bubbleSort(int *a,int n)  
// to perform Bubble Sort
{
	int i, j, temp;
	for(i = 0 ; i < n-1 ; ++i)
		for(j = 0; j < n-i-1 ; ++j)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	return a;
}

int* bubbleSortAdaptive(int *a,int n)  
// to perform Bubble Sort (an efficient version in the best case)
{
	int i, j, temp, swapped;
	swapped = TRUE;
	for(i = 0 ; i < n-1 && swapped; ++i)
	{
		swapped = FALSE;
		for(j = 0; j < n-i-1 ; ++j)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swapped = TRUE;
			}
	}
	return a;
}

int* selectionSort(int *a,int n) 
// to perform Selection Sort
{
	int i, j, temp, minIndex;
	for(i = 0; i < n-1; ++i)
	{
		minIndex = i;
		for(j = i+1; j < n; ++j)
			if(a[j] < a[minIndex])
				minIndex = j;
		
		temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;
	}
	return a;
}

int* insertionSort(int *a,int n)  
// to perform Insertion Sort
{
	int i, j, temp;
	for(i = 1; i < n; ++i)
	{
		temp = a[i];
		for(j = i-1; j>=0 && a[j]>temp; --j)
			a[j+1] = a[j];
		a[j+1] = temp;	
	}
	return a;
}

int* shellSort(int *a,int n) 
// to perform Shell Sort
{
	int increment, start;
	increment = n; 
	do
	{
		increment = increment/3;  // change according to any gaping sequence
		for(start = 0; start < increment; ++start)
			a = sortInterval(a,n,start,increment);
		
		//printf("\nincrement=%d\n",increment);
	}
	while(increment > 1);
	return a;
}

int* sortInterval(int *a,int n,int start,int increment)  
// to perform Insertion Sort on the chosen interval (refer Shell sort)
{
	int i, j, temp;
	for(i = start + increment; i < n; i = i + increment)
	{
		temp = a[i];
		for(j = i - increment; j>=start && a[j]>temp; j = j - increment)
			a[j+increment] = a[j];
		a[j+increment] = temp;	
	}
	return a;
}

int* mergeSort(int *a,int low,int high)  
// to perform Merge Sort (divide)
{
	int mid;
	if(low < high)
	{
		mid = low + (high-low)/2;
		// DIVIDE
		a = mergeSort(a,low,mid);  
		a = mergeSort(a,mid+1,high);
		// CONQUER
		a = mergeEfficient(a,low,mid,high);  // the merge() function can also be invoked in this step 
		// mergeEfficient() is used because it doesn't copy all elements to the auxiliary array
 	}
	return a;
}

int *merge(int *a,int low,int mid,int high)  
// to merge the subsequent divisions (conquer)
{
	int *b, i, j, k;
	b = allocateSpace(high-low+mid); // auxiliary array
	for(i = low; i<= high; ++i)
		b[i] = a[i];  // copy all elements
	
	i = low, j = mid + 1, k = low;
	while(i<=mid && j<=high)
	{
		if(b[i] <= b[j])
			a[k++] = b[i++];
		else
			a[k++] = b[j++]; 
	}
	while(i<=mid)
		a[k++] = b[i++];
	
	return a;
}

int *mergeEfficient(int *a,int low,int mid,int high)  
/* to merge the subsequent divisions (conquer) 
	Efficient version: The auxiliary array 'b' stores only the first half elements */
{
	int *b, i, j, k;
	b = allocateSpace(high-low+mid); // auxiliary array
	for(i = 0, j = low; j<= mid; ++i, ++j)
		b[i] = a[j];  // copy all elements
	
	i = 0,  k = low;
	while(k<j && j<=high)
	{
		if(b[i] <= a[j])
			a[k++] = b[i++];
		else
			a[k++] = a[j++]; 
	}
	while(k<j)
		a[k++] = b[i++];
	
	return a;		

}

int* quickSort(int *a,int low,int high)
// to perform Quick Sort (conquer)
{
	int pivot;
	if(low<high)
	{
		a = partitionLomuto(a,low,high,&pivot);
		/* 
			partitionLomuto() uses one index and use it to traverse the array
			partitionHoare() uses two indices and uses to to traverse the array from either directions
		*/
		// pivot is placed at its original position
		a = quickSort(a,low,pivot-1);
		a = quickSort(a,pivot+1,high);
	}
	return a;
}

int* partitionHoare(int *a,int low,int high,int *fixed)   
// to perform partion using Hoare partition
{
	int i,j,pivot,temp;
	i = low;
	j = high;
	pivot = a[low];
	while(i<j)
	{
		while(a[i]<=pivot && i<=high)
			++i;
			
		while(a[j]>pivot)
			--j;
		
		if(i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[j];
	a[j] = a[low];
	a[low] = temp;
	*fixed = j;
	
	return a;
}

int* partitionLomuto(int *a,int low,int high,int *fixed)
// to perform partion using Lomuto partition
{
	int i,j,temp,pivot;
	i = low - 1;
	pivot = a[high];
	for(j = low; j < high; ++j)
	{
		if(a[j] <= pivot)
		{
			++i;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i+1];
	a [i+1] =  a[high];
	a[high] = temp;
	*fixed = i+1;

	return a;
}

int findMax(int *a,int n)  
// to find the maximum from an array
{
	int i,max;
	max = a[0];
	for(i = 1 ; i < n; ++i)
		if( a[i] > max)
			max = a[i];
	return max;
}

int* countingSort(int *A,int n) 
// to perform Counting Sort
{
	int *B, *C, i, j, k;
	
	k = findMax(A,n);
	
	B = allocateSpaceInit(n);
	C = allocateSpaceInit(k+1);
	
	for(j = 0; j < n; ++j)
		C[A[j]] = C[A[j]] + 1;
		
	printf("\nThe frequency array: \n");
	displayArray(C,k+1);
	
	for(i = 1; i <= k; ++i)
		C[i] = C[i] + C[i-1];
		
	printf("\nThe cumulative frequency array: \n");
	displayArray(C,k+1);
	
	for(j = n-1; j>=0; --j)
	{
		B[C[A[j]]-1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	return B;
}
