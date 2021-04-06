#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
/*
Ввести длину массива натуральных чисел и диапазон его значений (минимально возможное и максимально возможное значения). Ввести массив. Вывести упорядоченный массив при помощи сортировки подсчётом: для каждого возможного значения массива заводится свой счётчик; каждый новый элемент массива увеличивает соответствующий его значению счётчик на 1; на экран выводятся все значения из возможного диапазона в количестве, соответствующем значению их счётчиков.

*/
int main () {
	int len = 0, min = 0, max = 0;
	printf("Enter a length of an array:\n");
	scanf("%d", &len);
	if (len <= 0) {
		printf("INVALID INPUT!\n");
		return 1;
	}
	printf("Enter a min value:");
	scanf("%d", &min);
	if (min < 0) {
		printf("INVALID INPUT!\n");
		return 1;
	}
	printf("Enter a max value:");
	scanf("%d", &max);
	if (min >= max) {
		printf("INVALID INPUT!\n");
		return 1;
	}
	int i = 0;
	int *arr = (int*) malloc(len * sizeof(int));
	if (arr == NULL) {
		printf("NOT ENOUGH MEMORY!\n");
		return 2;
	}
	while (i < len) {
		printf("Enter %d element:", i);
		scanf("%d", &arr[i]);
		if ((arr[i] < 0) || (arr[i] > max) || (arr[i] < min)) {
			printf("INVALID INPUT!\n");
			return 1;
		}
		i++;
	}
	int *counters = (int*) calloc((max + 1), sizeof(int));
	if (arr == NULL) {
		printf("NOT ENOUGH MEMORY!\n");
		return 2;
	}
	counting_sort(arr, counters, len, min, max);
	free(counters);
	i = 0;
	printf("Sorted array: ");
	while (i < len) {
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);	
	return 0;
}
