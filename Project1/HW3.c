//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#define MAX_ELEMENT 280000
//
//clock_t start, finish;
//double bubbleTime, insertionTime, selectionTime, shellTime, mergeTime, quickTime, heapTime;
//int count;
//char** temp;
//
//// ���� ������ ���� ����ü ���� �� �ʱ�ȭ �޼ҵ� ����
//typedef struct {
//	char** heap;
//	int heapSize;
//} HeapType;
//
//HeapType* create()
//{
//	return (HeapType*)malloc(sizeof(HeapType));
//}
//
//void init(HeapType* h)
//{
//	h->heapSize = 0;
//	h->heap = (char**)malloc(sizeof(char*) * count);
//}
//
//// ������ �޼ҵ�
//void reSort(char** arrBuf, char** arr, int count) 
//{
//	printf("-------------Re Sort------------\n");
//	for (int i = 0; i < count; i++) {
//		strcpy(arrBuf[i], arr[i]);
//	}
//}
//
//// �迭 ���
//void printArray(char** arr, int n) 
//{
//	for (int i = 0; i < n; i++) {
//		printf("%s\n", arr[i]);
//	}
//}
//
//// ���� ����
//void bubbleSort(char** arr, int n) 
//{
//	int i, j;
//	char* temp;
//	printf("----------Bubble Sort-----------");
//	printf("Wait....");
//	start = clock();
//	for (i = n - 1; i > 0; i--) {
//		for (j = 0; j < i; j++) {
//			if (strcmp(arr[j], arr[j + 1]) == 1) {
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	finish = clock();
//	bubbleTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Bubble Sort Success....\n");
//}
//
//// ���� ����
//void insertionSort(char** arr, int n) 
//{
//	int i, j;
//	char* key = NULL;
//
//	printf("---------Insertion Sort---------");
//	printf("Wait....");
//	start = clock();
//	for (i = 1; i < n; i++) {
//		key = arr[i];
//		for (j = i - 1; j >= 0 && strcmp(arr[j], key) == 1; j--) {
//			arr[j + 1] = arr[j];
//		}
//		arr[j + 1] = key;
//	}
//	finish = clock();
//	insertionTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Insertion Sort Success....\n");
//}
//
//// ���� ����
//void selectionSort(char** arr, int n) 
//{
//	int i, j, index;
//	char* temp = NULL;
//
//	printf("---------Selection Sort---------");
//	printf("Wait....");
//	start = clock();
//	for (i = 0; i < n - 1; i++) {
//		index = i;
//		for (j = i + 1; j < n; j++) {
//			if (strcmp(arr[index], arr[j]) >= 0) {
//				index = j;
//			}
//			temp = arr[i];
//			arr[i] = arr[index];
//			arr[index] = temp;
//		}
//	}
//	finish = clock();
//	selectionTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Selection Sort Success....\n");
//}
//
//// �� ����
//void shellInsertionSort(char** arr, int first, int last, int gap) 
//{
//	int i, j;
//	char* key;
//	for (i = first + gap; i <= last; i = i + gap) {
//		key = arr[i];
//		for (j = i - gap; j >= first && strcmp(arr[j], key) == 1; j = j - gap) {
//			arr[j + gap] = arr[j];
//		}
//		arr[j + gap] = key;
//	}
//}
//
//void shellSort(char** arr, int n) 
//{
//	int i, gap;
//	printf("-----------Shell Sort-----------");
//	printf("Wait....");
//	start = clock();
//	for (gap = n / 2; gap > 0; gap = gap / 2) {
//		if ((gap % 2) == 0) gap++;
//		for (i = 0; i < gap; i++) {
//			shellInsertionSort(arr, i, n - 1, gap);
//		}
//	}
//	finish = clock();
//	shellTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Shell Sort Success....\n");
//}
//
//// �պ� ����
//void merge(char** arr, int left, int mid, int right)
//{
//	int i, j, k, l;
//	i = left;
//	j = mid + 1;
//	k = left;
//
//	// ���� ���ĵ� list�� Merge��
//	while (i <= mid && j <= right) {
//		if (strcmp(arr[i], arr[j]) <= 0 ){
//			strcpy(temp[k++], arr[i++]);
//		}
//		else {
//			strcpy(temp[k++], arr[j++]);
//		}
//	}
//	if (i > mid) {			// �����ִ� ���ڵ� �ϰ� ����
//		for (l = j; l <= right; l++) {
//			strcpy(temp[k++], arr[l]);
//		}
//	}
//	else {					// �����ִ� ���ڵ� �ϰ� ����
//		for (l = i; l <= mid; l++) {
//			strcpy(temp[k++], arr[l]);
//		}
//	}
//
//	// ������ �迭�� �� ����
//	for (l = left; l <= right; l++) {
//		strcpy(arr[l], temp[l]);
//	}
//
//}
//
//void mergeSort(char** arr, int left, int right) 
//{
//	int mid, i;
//
//	if (left < right) {
//		mid = (left + right) / 2;		// ����Ʈ �յ� ����
//		mergeSort(arr, left, mid);		// �κ� ����Ʈ ����
//		mergeSort(arr, mid + 1, right);	// �κ� ����Ʈ ����
//		merge(arr, left, mid, right);	// �պ�
//	}
//
//}
//
//// �� ����
//int partition(char** arr, int left, int right)
//{
//	int low, high;
//	char pivot[100], temp[100];
//	low = left;
//	high = right + 1;
//	strcpy(pivot, arr[left]);
//
//	do {
//		do
//			low++;
//		while (low <= right && strcmp(arr[low], pivot) < 0);
//		do
//			high--;
//		while (high >= left && strcmp(arr[high], pivot) > 0);
//
//		if (low < high) {
//			strcpy(temp, arr[low]);
//			strcpy(arr[low], arr[high]);
//			strcpy(arr[high], temp);
//		}
//	} while (low < high);
//
//	strcpy(temp, arr[left]);
//	strcpy(arr[left], arr[high]);
//	strcpy(arr[high], temp);
//
//	return high;
//}
//
//void quickSort(char** arr, int left, int right) 
//{
//	int quick;
//	if (left < right) {
//		quick = partition(arr, left, right);
//		quickSort(arr, left, quick - 1);
//		quickSort(arr, quick + 1, right);
//	}
//}
//
//// ���� ����
//void insertHeap(HeapType* h, char* item)
//{
//	int i;
//	i = ++(h->heapSize);
//	
//	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
//	while ((i != 1) && strcmp(item, h->heap[i / 2]) > 0)
//	{
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//	h->heap[i] = item;
//}
//
//char* deleteHeap(HeapType* h)
//{
//	int parent, child;
//	char item[100], temp[100];
//
//	strcpy(item, h->heap[1]);
//	strcpy(temp, h->heap[(h->heapSize)--]);
//
//	parent = 1;
//	child = 2;
//
//	while (child <= h->heapSize){
//		if ((child < h->heapSize) && strcmp(h->heap[child], &h->heap[child + 1]) < 0) {
//			child++;
//		}
//
//		if (strcmp(temp, h->heap[child]) >= 0) break;
//
//		strcpy(h->heap[parent], h->heap[child]);
//		parent = child;
//		child *= 2;
//	}
//
//	strcpy(h->heap[parent], temp);
//	return item;
//}
//
//void heapSort(char ** arr, int n)
//{
//	int i;
//	HeapType* h;
//	
//	h = create();
//	init(h);
//	for (i = 0; i < n; i++) {
//		insertHeap(h, arr[i]);
//	}
//	for (i = (n - 1); i >= 0; i--) {
//		strcpy(arr[i], deleteHeap(h));
//	}
//	free(h);
//}
//
//// ����
//int main(void)
//{
//	// �ʿ��� ���� �� instance ����
//	int i;
//	char** stringArr = NULL, ** stringArrBuf = NULL;
//	char* ptr = NULL;
//	char buf[100];
//	FILE* fp;
//
//	// Open File
//	fp = fopen("text.txt", "r");
//	// NULL Check
//	while (fp == NULL) {
//		printf("File Not Found!\n");
//		return -1;
//	}
//
//	// Read File (counting)
//	while (!feof(fp)) {
//		int error = fscanf(fp, "%s", buf);
//		if (error == EOF) {
//			printf("Error reading file!\n");
//			return error;
//		}
//		count++;
//	}
//	rewind(fp);			// Initialize File Pointer
//
//	// ���� ���� �޸� �Ҵ�
//	stringArr = malloc(sizeof(char*) * count);
//	stringArrBuf = malloc(sizeof(char*) * count);
//
//	// NULL Check
//	if (stringArr == NULL || stringArrBuf == NULL) {
//		printf("Memory Allocation Error!\n");
//		free(stringArr);
//		free(stringArrBuf);
//		return -1;
//	}
//
//	// counting�� �������� i�� �۰ų� ������ ���� ��� (�ᱹ ����)
//	for (i = 0; i < count || !feof(fp); i++) {
//		// Error Check
//		int error = fscanf(fp, "%s", &buf);
//		if (error == EOF) {
//			printf("Error reading file!\n");
//			return error;
//		}
//
//		// ���� ���� �޸� �Ҵ� (���ڿ� Size��ŭ �Ҵ� ��)
//		ptr = malloc(sizeof(char) * 100);
//		stringArr[i] = malloc(sizeof(char) * 100);
//		stringArrBuf[i] = malloc(sizeof(char) * 100);
//
//		// NULL Check
//		if (ptr == NULL || stringArr[i] == NULL || stringArrBuf[i] == NULL) {
//			printf("Memory Allocation Error!\n");
//			free(stringArr[i]);
//			free(stringArrBuf[i]);
//			free(ptr);
//			return -1;
//		}
//
//		// ���Ͽ� ����� ���ڿ� �� �迭�� ����
//		strcpy(ptr, buf);
//		strcpy(stringArrBuf[i], ptr);
//		strcpy(stringArr[i], stringArrBuf[i]);
//	}
//	fclose(fp);
//
//	//printf("---------Default Array----------\n");
//	//printArray(stringArrBuf, count);
//
//	// ���� ����
//	bubbleSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// ���� ����
//	insertionSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// ���� ����
//	selectionSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// �� ����
//	shellSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// �պ� ����
//	printf("-----------Merge Sort-----------");
//	printf("Wait....");
//	temp = malloc(sizeof(char*) * count);			// Merge Sort�� ���� ������ (char**) �迭
//	for (i = 0; i < count; i++) {
//		temp[i] = malloc(sizeof(char) * 100);
//	}
//	start = clock();
//	mergeSort(stringArrBuf, 0, count-1); 
//	finish = clock();
//	mergeTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Merge Sort Success....\n");
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//	// �Ҵ� ����
//	for (i = 0; i < count; i++) {
//		free(temp[i]);
//	}
//	free(temp);
//
//	// �� ����
//	printf("-----------Quick Sort-----------");
//	printf("Wait....");
//	start = clock();
//	quickSort(stringArrBuf, 0, count - 1); 
//	finish = clock();
//	quickTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Quick Sort Success....\n");
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// ���� ����
//	printf("------------Heap Sort-----------");
//	printf("Wait....");
//	start = clock();
//	heapSort(stringArrBuf, count);
//	finish = clock();
//	heapTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Heap Sort Success....\n");
//	//printArray(stringArrBuf, count);
//
//	printf("���� ���� ���� �ð� : %lf\n", bubbleTime);
//	printf("���� ���� ���� �ð� : %lf\n", insertionTime);
//	printf("���� ���� ���� �ð� : %lf\n", selectionTime);
//	printf("�� ���� ���� �ð� : %lf\n", shellTime);
//	printf("�պ� ���� ���� �ð� : %lf\n", mergeTime);
//	printf("�� ���� ���� �ð� : %lf\n", quickTime);
//	printf("���� ���� ���� �ð� : %lf\n", heapTime);
//	printf("test");
//
//	//// TODO : �Ҵ� ���� ����
//	for (i = 0; i < count; i++) {
//		//free(stringArrBuf[i]);
//		free(stringArr[i]);
//	}
//	//free(stringArrBuf);
//	free(stringArr);	return 0;
//}