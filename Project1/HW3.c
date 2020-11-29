#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

clock_t start, finish;
double bubbleTime, insertionTime, selectionTime;

void reSort(char** arrBuf, char** arr, int count) {
	printf("-------------Re Sort------------\n");
	for (int i = 0; i < count; i++) {
		strcpy(arrBuf[i], arr[i]);
	}
}

void printArray(char** arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}
	//printf("--------------------------------\n");

}

void bubbleSort(char** arr, int n) {
	int i, j, temp;
	printf("----------Bubble Sort-----------");
	printf("Wait....");
	start = clock();
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(arr[j], arr[j + 1]) == 1) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	finish = clock();
	bubbleTime = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Bubble Sort Success....\n");
	//printf("실행 시간 : %lf\n", bubbleTime);
	printArray(arr, n);
}

void insertionSort(char** arr, int n) {
	int i, j;
	char* key;
	printf("---------Insertion Sort---------");
	printf("Wait....");
	start = clock();
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && strcmp(arr[j], key) == 1; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
	finish = clock();
	insertionTime = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Insertion Sort Success....\n");
	//printf("실행 시간 : %lf\n", insertionTime);
	printArray(arr, n);
}

void selectionSort(char** arr, int n) {
	int i, j, index, temp;

	printf("---------Selection Sort---------");
	printf("Wait....");
	start = clock();
	for (i = 0; i < n - 1; i++) {
		index = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(arr[j], arr[index]) == -1) {
				index = j;
			}
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
	finish = clock();
	selectionTime = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Selection Sort Success....\n");
	//printf("실행 시간 : %lf\n", selectionTime);
	printArray(arr, n);
}

void shellSort(char** arr, int n) {
	printArray(arr, n);
}

void mergeSort(char** arr, int n) {
	printArray(arr, n);
}

void quickSort(char** arr, int n) {
	printArray(arr, n);
}

int main(void)
{
	int count = 0, i, len, status = 0;
	char** stringArr, ** stringArrBuf;
	char* ptr;
	char buf[100];
	FILE* fp;
	fp = fopen("text.txt", "rt");
	// 예외 처리
	while (fp == NULL) {
		printf("File Not Found!\n");
		return -1;
	}

	while (!feof(fp)) {
		fscanf(fp, "%s", buf);
		count++;
	}
	rewind(fp);

	stringArr = (char**)malloc(sizeof(char*) * count);
	stringArrBuf = (char**)malloc(sizeof(char*) * count);
	// 배열 입력받음
	i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s", buf);
		ptr = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(ptr, buf);

		// NULL Check
		if (ptr == NULL) {
			printf("Memory Allocaltion Error!!\n");
			return -1;
		}
		stringArr[i] = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		stringArrBuf[i] = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		stringArrBuf[i] = ptr;
		strcpy(stringArr[i], stringArrBuf[i]);
		i++;
	}
	fclose(fp);

	printf("---------Default Array----------\n");
	printArray(stringArrBuf, count);

	// 버블 정렬
	bubbleSort(stringArrBuf, count);reSort(stringArrBuf, stringArr, count);
	printArray(stringArrBuf, count);

	// 삽입 정렬
	insertionSort(stringArrBuf, count); reSort(stringArrBuf, stringArr, count);
	printArray(stringArrBuf, count);

	// 선택 정렬
	selectionSort(stringArrBuf, count); reSort(stringArrBuf, stringArr, count);
	printArray(stringArrBuf, count);

	printf("버블 정렬 실행 시간 : %lf\n", bubbleTime);
	printf("삽입 정렬 실행 시간 : %lf\n", insertionTime);
	printf("선택 정렬 실행 시간 : %lf\n", selectionTime);

	for (int i = 0; i < count; i++) {
		printf("%s\n", stringArr[i]);
		printf("%s\n", stringArrBuf[i]);
		//free(stringArr[i]);
		//free(stringArrBuf[i]);
	}
	free(stringArr);
	free(stringArrBuf);

	return 0;
}