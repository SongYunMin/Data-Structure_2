#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

clock_t start, finish;
double bubbleTime, insertionTime, selectionTime, shellTime;

int stringLength(char* str) {
	int i = 0;
	for (i = 0; str[i] != '\0'; i++);

	return i + 1;
}


void reSort(char** arrBuf, char** arr, int count) {
	printf("-------------Re Sort------------\n");
	for (int i = 0; i < count; i++) {
		// ISSUE : Access 위반
		strcpy_s(arrBuf[i], stringLength(arr[i]), arr[i]);
	}
}

void printArray(char** arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}

}

//
void bubbleSort(char** arr, int n) {
	int i, j;
	char* temp;
	temp = malloc(sizeof(char) * 100);
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
	bubbleTime = ((double)finish - start) / CLOCKS_PER_SEC;
	printf("Bubble Sort Success....\n");
	//printArray(arr, n);
	free(temp);
}

// 삽입 정렬
void insertionSort(char** arr, int n) {
	int i, j;
	char* key = NULL;

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
	insertionTime = ((double)finish - start) / CLOCKS_PER_SEC;
	printf("Insertion Sort Success....\n");
	//printArray(arr, n);
}

// 선택 정렬
void selectionSort(char** arr, int n) {
	int i, j, index;
	char* temp = NULL;
	temp = malloc(sizeof(char) * 100);

	printf("---------Selection Sort---------");
	printf("Wait....");
	start = clock();
	for (i = 0; i < n - 1; i++) {
		index = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(arr[index], arr[j]) == 1) {
				index = j;
			}
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
	finish = clock();
	selectionTime = ((double)finish - start) / CLOCKS_PER_SEC;
	printf("Selection Sort Success....\n");
	//printArray(arr, n);
	free(temp);
}

// 쉘 정렬
void shellInsertionSort(char** arr, int first, int last, int gap) {
	int i, j;
	char* key;

	for (i = first + gap; i <= last; i = i + gap) {
		key = arr[i];
		for (j = i - gap; j >= first && strcmp(arr[j], key) == 1; j = j - gap) {
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}


void shellSort(char** arr, int n) {
	int i, gap;
	printf("-----------Shell Sort-----------");
	printf("Wait....");
	start = clock();
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {
			shellInsertionSort(arr, i, n - 1, gap);
		}
	}
	finish = clock();
	shellTime = ((double)finish - start) / CLOCKS_PER_SEC;
	printf("Shell Sort Success....\n");
	//printArray(arr, n);
}

void mergeSort(char** arr, int n) {
	printArray(arr, n);
}

void quickSort(char** arr, int n) {
	printArray(arr, n);
}

int main(void)
{
	int count = 0, i, status = 0;
	char** stringArr = NULL, ** stringArrBuf = NULL;
	char* ptr = NULL;
	char buf[100];
	FILE* fp;
	fp = fopen("text.txt", "r");
	// 예외 처리
	while (fp == NULL) {
		printf("File Not Found!\n");
		return -1;
	}

	while (!feof(fp)) {
		int error = fscanf(fp, "%s", buf);
		if (error == EOF) {
			printf("Error reading file!\n");
			return error;
		}
		count++;
	}
	rewind(fp);

	stringArr = malloc(sizeof(char*) * count);
	stringArrBuf = malloc(sizeof(char*) * count);

	if (stringArr == NULL || stringArrBuf == NULL) {
		printf("Memory Allocation Error!\n");
		free(stringArr);
		free(stringArrBuf);
		return -1;
	}

	// 배열 입력받음
	for (i = 0; i < count || !feof(fp); i++) {
		int error = fscanf(fp, "%s", &buf);
		if (error == EOF) {
			printf("Error reading file!\n");
			return error;
		}

		ptr = malloc(sizeof(char) * stringLength(buf));
		stringArr[i] = malloc(sizeof(char) * stringLength(buf));
		stringArrBuf[i] = malloc(sizeof(char) * stringLength(buf));

		if (ptr == NULL || stringArr[i] == NULL || stringArrBuf[i] == NULL) {
			printf("Memory Allocation Error!\n");
			free(stringArr[i]);
			free(stringArrBuf[i]);
			free(ptr);
			return -1;
		}
		strcpy_s(ptr, stringLength(buf), buf);
		stringArrBuf[i] = ptr;
		strcpy_s(stringArr[i], stringLength(buf), stringArrBuf[i]);
	}
	fclose(fp);

	printf("---------Default Array----------\n");
	//printArray(stringArrBuf, count);

	// 버블 정렬
	bubbleSort(stringArrBuf, count); reSort(stringArrBuf, stringArr, count);
	//printArray(stringArrBuf, count);

	// 삽입 정렬
	insertionSort(stringArrBuf, count);
	reSort(stringArrBuf, stringArr, count);	// reSort 까지 문제 없음
	//printArray(stringArrBuf, count);

	// 선택 정렬
	// TODO : 정렬 값 이상하게 출력 됨 - 중복값에 대한 Issue 있는듯
	selectionSort(stringArrBuf, count); reSort(stringArrBuf, stringArr, count);
	//printArray(stringArrBuf, count);

	printf("버블 정렬 실행 시간 : %lf\n", bubbleTime);
	printf("삽입 정렬 실행 시간 : %lf\n", insertionTime);
	printf("선택 정렬 실행 시간 : %lf\n", selectionTime);
	printf("쉘 정렬 실행 시간 : %lf\n", shellTime);

	////// TODO : 할당 해제 에러
	//for (i = 0; i < count; i++) {
	//	free(stringArr[i]);
	//	free(stringArrBuf[i]);
	//}
	//free(stringArr);
	//free(stringArrBuf);

	return 0;
}