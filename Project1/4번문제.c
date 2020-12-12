//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_ELEMENT 100
//
//typedef struct {
//	char name[100];
//	int ko;
//	int en;
//	int mt;
//	int score;
//}Student;
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
//
//// 메인
//int main(void)
//{
//	// 필요한 변수 및 instance 생성
//	int i;
//	int ko, en, mh;
//	int score = 0, studentNum = 0;
//	char name[100];
//	int count = 0;
//
//	Student* list[MAX_ELEMENT];
//	FILE* fp;
//
//	// Open File
//	fp = fopen("sort_data.txt", "r");
//	// NULL Check
//	while (fp == NULL) {
//		printf("File Not Found!\n");
//		return -1;
//	}
//
//	// Read File (counting)
//	while (!feof(fp)) {
//		int error = fscanf(fp, "%s %d %d %d %d", name, &ko, &en, &mh, &score);
//		if (error == EOF) {
//			printf("Error reading file!\n");
//			return error;
//		}
//		count++;
//	}
//	rewind(fp);			// Initialize File Pointer
//
//	i = 0;
//	*list = malloc(sizeof(Student) * count);
//	while (i < count) {
//		int error = fscanf(fp, "%s %d %d %d %d", name, &ko, &en, &mh, &score);
//		if (error == EOF) {
//			printf("Error reading file!\n");
//			return error;
//		}
//		list[i] = malloc(sizeof(Student));
//
//		strcpy(list[i]->name,name);
//		list[i]->ko = ko;
//		list[i]->en = en;
//		list[i]->mt = mh;
//		list[i]->score = score;
//
//		i++;
//	}
//
//	//Test Code
//	printf("======= 입력 데이터 ========\n");
//	for (int i = 0; i < count; i++) {
//		printf("%d   %s \t%d\n", list[i]->name, list[i]->ko, list[i]->en, 
//			list[i]->mt, list[i]->score);
//	}
//	printf("============================\n");
//
///*
//3번푸느라 시간이 없었습니다..
//한학기 동안 고생 많으셨습니다 교수님!
//*/
//
//	fclose(fp);
//}