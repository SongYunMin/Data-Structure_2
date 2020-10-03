//// 이진 트리 탐색
//#include <stdio.h>
//
//int main(void)
//{
//	FILE* fp;
//	int arr[10000], count = 0;
//	fp = fopen("data_2.txt", "rt");
//
//	if (fp == NULL) {
//		printf("File Not Found!!\n");
//		exit(-1);
//	}
//
//	for (int i = 0; i < 10000; i++) {
//		fscanf(fp, "%d", &arr[i]);
//		count++;
//	}
//
//	for (int i = 0; i < 10000; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n\n");
//
//	printf("count = %d\n", count);
//
//	return 0;
//}