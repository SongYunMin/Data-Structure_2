//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//
//clock_t start, finish;
//double bubbleTime, insertionTime, selectionTime, shellTime;
//
//int stringLength(char* str) 
//{
//	int i = 0;
//	for (i = 0; str[i] != '\0'; i++);
//
//	return i + 1;
//}
//
//void reSort(char** arrBuf, char** arr, int count) 
//{
//	printf("-------------Re Sort------------\n");
//	for (int i = 0; i < count; i++) {
//		// ISSUE : Access 위반
//		strcpy_s(arrBuf[i], stringLength(arr[i]), arr[i]);
//	}
//}
//
//void printArray(char** arr, int n) 
//{
//	for (int i = 0; i < n; i++) {
//		printf("%s\n", arr[i]);
//	}
//}
//
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
//			if (strcmp(arr[index], arr[j]) == 1) {
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
//
//void shellInsertionSort(char** arr, int first, int last, int gap) 
//{
//	int i, j;
//	char* key;
//
//	for (i = first + gap; i <= last; i = i + gap) {
//		key = arr[i];
//		for (j = i - gap; j >= first && strcmp(arr[j], key) == 1; j = j - gap) {
//			arr[j + gap] = arr[j];
//		}
//		arr[j + gap] = key;
//	}
//}
//
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
//void merge(char** arr, int left, int mid, int right, char** buf)
//{
//	int i, j, k, l;
//	i = left;
//	j = mid + 1;
//	k = left;
//
//	// 분할 정렬된 list를 Merge함
//	while (i <= mid && j <= right) {
//		if (strcmp(arr[i], arr[j]) <= 0 ){
//			strcpy(buf[k++], arr[i++]);
//		}
//		else {
//			strcpy(buf[k++], arr[j++]);
//		}
//	}
//	if (i > mid) {			// 남아있는 레코드 일괄 복사
//		for (l = j; l <= right; l++) {
//			strcpy(buf[k++], arr[l]);
//		}
//	}
//	else {					// 남아있는 레코드 일괄 복사
//		for (l = i; l <= mid; l++) {
//			strcpy(buf[k++], arr[l]);
//		}
//	}
//
//	// 원래의 배열로 재 복사
//	for (l = left; l <= right; l++) {
//		strcpy(arr[l], buf[l]);
//	}
//}
//
//void mergeSort(char** arr, int left, int right) 
//{
//	int mid, i;
//	char** buf = NULL;
//	// 동적 할당
//	buf = (char **)malloc(sizeof(char*) * right);
//	for (i = 0; i < right; i++) {
//		buf[i] = (char *)malloc(sizeof(char) * 200);
//	}
//	
//	if (left < right) {
//		mid = (left + right) / 2;		// 리스트 균등 분할
//		mergeSort(arr, left, mid);		// 부분 리스트 정렬
//		mergeSort(arr, mid + 1, right);	// 부분 리스트 정렬
//		merge(arr, left, mid, right, buf);	// 합병
//	}
//}
//
//void quickSort(char** arr, int n) 
//{
//	printArray(arr, n);
//}
//
//int main(void)
//{
//	int count = 0, i, status = 0;
//	char** stringArr = NULL, ** stringArrBuf = NULL;
//	char* ptr = NULL;
//	char buf[100];
//	FILE* fp;
//
//	fp = fopen("text.txt", "r");
//	// 예외 처리
//	while (fp == NULL) {
//		printf("File Not Found!\n");
//		return -1;
//	}
//
//	while (!feof(fp)) {
//		int error = fscanf(fp, "%s", buf);
//		if (error == EOF) {
//			printf("Error reading file!\n");
//			return error;
//		}
//		count++;
//	}
//	rewind(fp);
//
//	stringArr = malloc(sizeof(char*) * count);
//	stringArrBuf = malloc(sizeof(char*) * count);
//
//	if (stringArr == NULL || stringArrBuf == NULL) {
//		printf("Memory Allocation Error!\n");
//		free(stringArr);
//		free(stringArrBuf);
//		return -1;
//	}
//
//	// 배열 입력받음
//	for (i = 0; i < count || !feof(fp); i++) {
//		int error = fscanf(fp, "%s", &buf);
//		if (error == EOF) {
//			printf("Error reading file!\n");
//			return error;
//		}
//
//		ptr = malloc(sizeof(char) * stringLength(buf));
//		stringArr[i] = malloc(sizeof(char) * stringLength(buf));
//		stringArrBuf[i] = malloc(sizeof(char) * stringLength(buf));
//
//		if (ptr == NULL || stringArr[i] == NULL || stringArrBuf[i] == NULL) {
//			printf("Memory Allocation Error!\n");
//			free(stringArr[i]);
//			free(stringArrBuf[i]);
//			free(ptr);
//			return -1;
//		}
//		strcpy(ptr, buf);
//		stringArrBuf[i] = ptr;
//		strcpy(stringArr[i], stringArrBuf[i]);
//	}
//	fclose(fp);
//
//	printf("---------Default Array----------\n");
//	printArray(stringArrBuf, count);
//
//	// 버블 정렬
//	bubbleSort(stringArrBuf, count); printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 삽입 정렬
//	insertionSort(stringArrBuf, count); printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 선택 정렬
//	selectionSort(stringArrBuf, count); printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 쉘 정렬
//	shellSort(stringArrBuf, count); printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	// 합병 정렬
//	mergeSort(stringArrBuf, 0, count-1); printArray(stringArrBuf, count);
//	reSort(stringArrBuf, stringArr, count);
//
//	printf("버블 정렬 실행 시간 : %lf\n", bubbleTime);
//	printf("삽입 정렬 실행 시간 : %lf\n", insertionTime);
//	printf("선택 정렬 실행 시간 : %lf\n", selectionTime);
//	printf("쉘 정렬 실행 시간 : %lf\n", shellTime);
//
//	////// TODO : 할당 해제 에러
//	//for (i = 0; i < count; i++) {
//	//	free(stringArr[i]);
//	//	free(stringArrBuf[i]);
//	//}
//	//free(stringArr);
//	//free(stringArrBuf);
//
//	return 0;
//}