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
//// 히프 정렬을 위한 구조체 정의 및 초기화 메소드 정의
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
//// 재정렬 메소드
//void reSort(char** arrBuf, char** arr, int count) 
//{
//	printf("-------------Re Sort------------\n");
//	for (int i = 0; i < count; i++) {
//		strcpy(arrBuf[i], arr[i]);
//	}
//}
//
//// 배열 출력
//void printArray(char** arr, int n) 
//{
//	for (int i = 0; i < n; i++) {
//		printf("%s\n", arr[i]);
//	}
//}
//
//// 버블 정렬
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
//// 삽입 정렬
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
//// 선택 정렬
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
//// 쉘 정렬
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
//// 합병 정렬
//void merge(char** arr, int left, int mid, int right)
//{
//	int i, j, k, l;
//	i = left;
//	j = mid + 1;
//	k = left;
//
//	// 분할 정렬된 list를 Merge함
//	while (i <= mid && j <= right) {
//		if (strcmp(arr[i], arr[j]) <= 0 ){
//			strcpy(temp[k++], arr[i++]);
//		}
//		else {
//			strcpy(temp[k++], arr[j++]);
//		}
//	}
//	if (i > mid) {			// 남아있는 레코드 일괄 복사
//		for (l = j; l <= right; l++) {
//			strcpy(temp[k++], arr[l]);
//		}
//	}
//	else {					// 남아있는 레코드 일괄 복사
//		for (l = i; l <= mid; l++) {
//			strcpy(temp[k++], arr[l]);
//		}
//	}
//
//	// 원래의 배열로 재 복사
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
//		mid = (left + right) / 2;		// 리스트 균등 분할
//		mergeSort(arr, left, mid);		// 부분 리스트 정렬
//		mergeSort(arr, mid + 1, right);	// 부분 리스트 정렬
//		merge(arr, left, mid, right);	// 합병
//	}
//
//}
//
//// 퀵 정렬
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
//// 히프 정렬
//void insertHeap(HeapType* h, char* item)
//{
//	int i;
//	i = ++(h->heapSize);
//	
//	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
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
//// 메인
//int main(void)
//{
//	// 필요한 변수 및 instance 생성
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
//	// 세로 길이 메모리 할당
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
//	// counting된 변수보다 i가 작거나 파일의 끝일 경우 (결국 같음)
//	for (i = 0; i < count || !feof(fp); i++) {
//		// Error Check
//		int error = fscanf(fp, "%s", &buf);
//		if (error == EOF) {
//			printf("Error reading file!\n");
//			return error;
//		}
//
//		// 가로 길이 메모리 할당 (문자열 Size만큼 할당 함)
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
//		// 파일에 저장된 문자열 각 배열에 복사
//		strcpy(ptr, buf);
//		strcpy(stringArrBuf[i], ptr);
//		strcpy(stringArr[i], stringArrBuf[i]);
//	}
//	fclose(fp);
//
//	//printf("---------Default Array----------\n");
//	//printArray(stringArrBuf, count);
//
//	// 버블 정렬
//	bubbleSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 삽입 정렬
//	insertionSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 선택 정렬
//	selectionSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 쉘 정렬
//	shellSort(stringArrBuf, count); 
//	//printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 합병 정렬
//	printf("-----------Merge Sort-----------");
//	printf("Wait....");
//	temp = malloc(sizeof(char*) * count);			// Merge Sort를 위해 생성한 (char**) 배열
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
//	// 할당 해제
//	for (i = 0; i < count; i++) {
//		free(temp[i]);
//	}
//	free(temp);
//
//	// 퀵 정렬
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
//	// 히프 정렬
//	printf("------------Heap Sort-----------");
//	printf("Wait....");
//	start = clock();
//	heapSort(stringArrBuf, count);
//	finish = clock();
//	heapTime = ((double)finish - start) / CLOCKS_PER_SEC;
//	printf("Heap Sort Success....\n");
//	//printArray(stringArrBuf, count);
//
//	printf("버블 정렬 실행 시간 : %lf\n", bubbleTime);
//	printf("삽입 정렬 실행 시간 : %lf\n", insertionTime);
//	printf("선택 정렬 실행 시간 : %lf\n", selectionTime);
//	printf("쉘 정렬 실행 시간 : %lf\n", shellTime);
//	printf("합병 정렬 실행 시간 : %lf\n", mergeTime);
//	printf("퀵 정렬 실행 시간 : %lf\n", quickTime);
//	printf("히프 정렬 실행 시간 : %lf\n", heapTime);
//	printf("test");
//
//	//// TODO : 할당 해제 에러
//	for (i = 0; i < count; i++) {
//		//free(stringArrBuf[i]);
//		free(stringArr[i]);
//	}
//	//free(stringArrBuf);
//	free(stringArr);	return 0;
//}