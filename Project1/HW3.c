#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int count = 0;
	FILE* fp;
	fp = fopen("data.txt", "rt");

	// 예외 처리
	while (fp == NULL) {
		printf("File Not Found!\n");
		return -1;
	}

	while (!feof(fp)) {
		
	}



	return 0;
}