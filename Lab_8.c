#ifndef LAB_8_C
#define LAB_8_C
#include "functions.h"
void counting_sort (int *arr, int *counters, int len, int min, int max) {
	int i = 0;
	for (i = 0; i < len; i++) {
		counters[arr[i]]++;
	}
	int j = 0, k = 0;
	for (i = min; i < max + 1; i++) {
		for (j = 0; j < counters[i]; j++) {
			arr[k] = i;
			k++;
		}
	}
}
#endif
