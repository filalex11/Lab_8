#include <stdio.h>
#include <stdlib.h>
#include "functions_dop.h"
/*
	Реализовать пирамидальную сортировку.
*/
int main () {
	printf ("Enter a length of array:\n");
	int length = 0, i = 0;
	scanf ("%d", &length);
	int *arr = (int*) malloc (length * sizeof (int));
	printf ("Enter the elements of the array:\n");
	while (i < length) {
		scanf ("%d", &arr[i++]);
	}
	heap_sort (arr, length);
	printf ("Sorted array:\n");
	for (int i = 0; i < length; ++i) {
		printf ("%d ", arr[i]);
	}
	printf ("\n");
	return 0;
}
