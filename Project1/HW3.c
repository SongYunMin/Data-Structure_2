#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

clock_t start, finish;
double timeResult;

void printArray(char** arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}
	printf("--------------------------------\n\n");
}

void bubbleSort(char** arr, int n) {
	int i, j, temp;
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
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("----------Bubble Sort-----------\n");
	printf("실행 시간 : %lf\n", timeResult);
	printArray(arr, n);
}

void insertionSort(char** arr, int n) {
	int i, j;
	char* key;

	start = clock();
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && strcmp(arr[j], key) == 1; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
	finish = clock();
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("---------Insertion Sort---------\n");
	printf("실행 시간 : %lf\n", timeResult);
	printArray(arr, n);
}

void selectionSort(char** arr, int n) {
	int i, j, index, temp;
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
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("---------Selection Sort---------\n");
	printf("실행 시간 : %lf\n", timeResult);
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
	char** stringArr;
	char** stringArr_;
	char buf[100];
	FILE* fp;
	fp = fopen("text.txt", "rt");
	// 예외 처리
	while (fp == NULL) {
		printf("File Not Found!\n");
		return -1;
	}

	// 배열 입력받음
	while (!feof(fp)) {
		fscanf(fp, "%s", buf);
		 

		char* ptr = (char*)malloc(sizeof(char) * strlen(buf + 1));
		strcpy(ptr, buf);

		// 처음 입력 받을땐 malloc으로 초기화
		if (status == 0) {
			stringArr = (char*)malloc(sizeof(char) * strlen(buf + 1));
			stringArr[count++] = ptr;
			status++;
		}
		// 처음 이후 부터는 realloc으로 메모리 공간 재할당
		else {
			char** temp = malloc(sizeof(char) *
				(strlen(stringArr + 1) + strlen(buf + 1)));
			if (temp != NULL) {
				memcpy(temp, stringArr, sizeof(char) * strlen(buf + 1));
				free(stringArr);
				stringArr = temp;
			}
			//stringArr_ = (char*)realloc(stringArr, sizeof(char) *
			//	(strlen(stringArr+1) + strlen(buf + 1)));

			stringArr[count++] = ptr;
		}
	}
	
	printf("---------Default Array----------\n");
	printArray(stringArr, count);
	bubbleSort(stringArr, count);
	insertionSort(stringArr, count);
	selectionSort(stringArr, count);


	return 0;
}