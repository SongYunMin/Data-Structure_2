#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 100

typedef struct {
	int studentNum;
	char name[100];
	int score;
}element;

// ���� ������ ���� ����ü ���� �� �ʱ�ȭ �޼ҵ� ����
typedef struct {
	element heap[MAX_ELEMENT];
	int heapSize;
} HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heapSize = 0;
}


// �迭 ���
void printArray(char** arr, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}
}


// ���� ����
void insertHeap(HeapType* h, element item)
{
	int i;
	i = ++(h->heapSize);

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && item.score > h->heap[i / 2].score)
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element deleteHeap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heapSize)--];
	parent = 1;
	child = 2;

	while (child <= h->heapSize) {
		if ((child < h->heapSize) && (h->heap[child].score) < (h->heap[child + 1].score)) {
			child++;
		}

		if (temp.score >= h->heap[child].score) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;
	return item;
}

void heapSort(element* arr[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insertHeap(h, *arr[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		*arr[i] = deleteHeap(h);
	}
	free(h);
}

// ����
int main(void)
{
	// �ʿ��� ���� �� instance ����
	int i;
	int score = 0, studentNum = 0;
	char name[100];
	int count = 0;
	int error;

	element* list[MAX_ELEMENT];
	FILE* fp;

	// Open File
	fp = fopen("heap_data.txt", "r");
	// NULL Check
	while (fp == NULL) {
		printf("File Not Found!\n");
		return -1;
	}

	// Read File (counting)
	while (!feof(fp)) {
		error = fscanf(fp, "%d %s %d", &studentNum, name, &score);
		if (error == EOF) {
			printf("Error reading file!\n");
			return error;
		}
		count++;
	}
	rewind(fp);			// Initialize File Pointer

	i = 0;
	*list = malloc(sizeof(element) * count);
	while (i < count) {
		error = fscanf(fp, "%d %s %d", &studentNum, name, &score);
		if (error == EOF) {
			printf("Error reading file!\n");
			return error;
		}
		list[i] = malloc(sizeof(element));

		list[i]->studentNum = studentNum;
		strcpy(list[i]->name, name);
		list[i]->score = score;

		i++;
	}

	//Test Code
	printf("======= �Է� ������ ========\n");
	for (i = 0; i < count; i++) {
		printf("%d   %s \t%d\n", list[i]->studentNum, list[i]->name, list[i]->score);
	}
	printf("============================\n");
	heapSort(list, count);

	printf("==== ���� ����� ������ ====\n");
	//Test Code
	for (i = count - 1; i >= (count - 3); i--) {
		printf("%d   %s \t%d\n", list[i]->studentNum, list[i]->name, list[i]->score);
	}
	printf("============================\n");

	fclose(fp);
}