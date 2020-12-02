#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h>
#define MAX_SIZE 28000
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

#pragma warning(disable: 4996)

typedef struct {
	char str[MAX_SIZE];
}String;

void print(String list[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s ", list[i].str);
}

void selection_sort(String list[], int n) // 선택 정렬
{
	int i, j, least;
	String temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (strcmp(list[j].str, list[least].str) < 0) least = j;
		SWAP(list[i], list[least], temp);
	}
}

void insertion_sort(String list[], int n) // 삽입 정렬
{
	int i, j;
	String key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && strcmp(list[j].str, key.str) > 0; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

void bubble_sort(String list[], int n) // 버블 정렬
{
	int i, j;
	String temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (strcmp(list[j].str, list[j + 1].str) > 0) {
				SWAP(list[j], list[j + 1], temp);
			}
	}
}

void inc_insertion_sort(String list[], int first, int last, int gap)
{
	int i, j;
	String key;

	for (i = first + gap; i <= last; i = i + gap)
	{
		key = list[i];
		for (j = i - gap; j >= first && strcmp(key.str, list[j].str) < 0; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
void shell_sort(String list[], int n) // 쉘 정렬
{
	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2)
	{
		if ((gap % 2) == 0)
			gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}

String sorted[MAX_SIZE];
void merge(String list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left, j = mid + 1; k = left;

	while (i <= mid && j <= right) {
		if (strcmp(list[i].str, list[j].str) <= 0)
			strcpy(sorted[k++].str, list[i++].str);
		else
			strcpy(sorted[k++].str, list[j++].str);
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			strcpy(sorted[k++].str, list[l].str);
	else
		for (l = i; l <= mid; l++)
			strcpy(sorted[k++].str, list[l].str);
	for (l = left; l <= right; l++)
		strcpy(list[l].str, sorted[l].str);
}
void merge_sort(String list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int partition(String list[], int left, int right)
{
	String pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do {
			low++;
		} while (strcmp(list[low].str, pivot.str) < 0);
		do {
			high--;
		} while (strcmp(list[high].str, pivot.str) > 0);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}
void quick_sort(String list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

typedef struct {
	char key;
}element;
typedef struct {
	element heap[MAX_SIZE];
	int heap_size;
}HeapType;
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h)
{
	h->heap_size = 0;
}
void insert_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && strcmp(&item.key, &h->heap[i / 2].key) > 0)
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	strcpy(&h->heap[i].key, &item.key);
}
element delete_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && strcmp(&h->heap[child].key, &h->heap[child + 1].key) < 0)
			child++;
		if (strcmp(&temp.key, &h->heap[child].key) >= 0) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	strcpy(&h->heap[parent].key, &temp.key);
	return item;
}
void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++)
		insert_heap(h, a[i]);
	for (i = (n - 1); i >= 0; i--)
		a[i] = delete_heap(h);
	free(h);
}

int main()
{
	FILE* fp;
	String* list;
	element* heap_list;
	String temp;
	int count = 0;
	int select;
	clock_t start, stop;
	double duration;

	fp = fopen("text.txt", "r");

	if (fp == NULL) {
		printf("File Not Found\n");
		return 0;
	}

	while (!feof(fp)) {
		fscanf(fp, "%s ", &temp.str);
		count++;
	}
	list = (String*)malloc(sizeof(String) * count);
	heap_list = (element*)malloc(sizeof(element) * count);
	rewind(fp);
	count = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s ", &list[count].str);
		count++;
	}

	while (1)
	{
		printf("\n정렬 방법을 선택하세요(1. 선택정렬 2. 삽입정렬 3. 버블정렬 4. 쉘정렬 5. 합병정렬 6. 퀵정렬 7. 히프정렬 8. 종료) : ");
		scanf("%d", &select);

		start = clock();

		switch (select)
		{
		case 1:
			printf("<선택 정렬>\n");
			selection_sort(list, count);
			print(list, count);
			break;
		case 2:
			printf("<삽입 정렬>\n");
			insertion_sort(list, count);
			print(list, count);
			break;
		case 3:
			printf("<버블 정렬>\n");
			bubble_sort(list, count);
			print(list, count);
			break;
		case 4:
			printf("<쉘 정렬>\n");
			shell_sort(list, count);
			print(list, count);
			break;
		case 5:
			printf("<합병 정렬>\n");
			merge_sort(list, 0, count - 1);
			print(list, count);
			break;
		case 6:
			printf("<퀵 정렬>\n");
			quick_sort(list, 0, count - 1);
			print(list, count);
			break;
		case 7:
			while (!feof(fp)) {
				fscanf(fp, "%s ", &heap_list[count].key);
				count++;
			}
			printf("<히프 정렬>\n");
			heap_sort(heap_list, count);
			print(list, count);
			break;
		case 8:
			return 0;
		}

		stop = clock();
		duration = (double)(stop - start) / CLOCKS_PER_SEC;

		printf("\n걸린시간은 %f입니다.\n", duration);
	}

	free(list);
	fclose(fp);
	return 0;
}