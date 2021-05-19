#ifndef LAB_8_DOP_C
#define LAB_8_DOP_C
void sift (int *arr, int root, int bottom) {
	int max_child = 0;
	char done = 0;
	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)
			max_child = root * 2;
		else if (arr[root * 2] > arr[root * 2 + 1])
			max_child = root * 2;
		else
			max_child = root * 2 + 1;
		
		if (arr[root] < arr[max_child]) {
			int temp = arr[root];
			arr[root] = arr[max_child];
			arr[max_child] = temp;
			root = max_child;
		}
		else
			done = 1;
  }
}

void heap_sort(int *arr, int size) {
	int i = 0;
	for (i = size / 2; i >= 0; i--) {
		sift (arr, i, size - 1);
	}	
  	for (i = size - 1; i >= 1; i--) {
		arr[0] += arr[i];
		arr[i] = arr[0] - arr[i];
		arr[0] = arr[0] - arr[i];
		sift (arr, 0, i - 1);
	}
}
#endif
