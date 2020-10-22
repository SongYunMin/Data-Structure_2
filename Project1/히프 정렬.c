//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define MAX_ELEMENT 5
//
//int count;
//
//typedef struct {
//	int key;
//}element;
//
//typedef struct {
//	element heap[MAX_ELEMENT];
//	int heap_size;
//}HeapType;
//
//void init(HeapType* h)
//{
//	h->heap_size = 0;
//}
//
//void insert_min_heap(HeapType* h, element item)
//{
//	int i;
//	i = (h->heap_size)++;
//
//	while ((i != 1) && (item.key < h->heap[i / 2].key))
//	{
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//
//	h->heap[i] = item;
//}
//
//element delete_min_heap(HeapType* h)
//{
//	int parent, child;
//	element item, temp;
//
//	item = h->heap[1];
//	temp = h->heap[(h->heap_size)--];
//	parent = 1;
//	child = 2;
//
//	while (child <= h->heap_size)
//	{
//		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
//			child++;
//		if (temp.key <= h->heap[child].key) break;
//		h->heap[parent] = h->heap[child];
//		parent = child;
//		child *= 2;
//	}
//	h->heap[parent] = temp;
//	return item;
//}
//
//void heap_sort(element a[], int n)
//{
//	int i;
//	HeapType h;
//
//	init(&h);
//
//	for (i = 0; i < n; i++)
//	{
//		insert_min_heap(&h, a[i]);
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		a[i] = delete_min_heap(&h);
//	}
//}
//
//int main(void)
//{
//	int i, j;
//	element data[MAX_ELEMENT];
//
//	srand(time(NULL));
//	for (i = 0; i < MAX_ELEMENT; i++) // 100개의 랜덤 숫자 생성
//	{
//		data[i].key = rand() % MAX_ELEMENT;
//		for (j = 0; j < i; j++) // 기존 데이터 중 중복데이터 검색
//		{
//			if (data[i].key == data[j].key)
//			{
//				i--;
//				break;
//			}
//		}
//	}
//
//	printf("미정렬데이터\n");
//	for (i = 0; i < MAX_ELEMENT; i++)
//	{
//		if (i % 10 == 0 && i != 0)
//			printf("\n");
//		printf("%2d  ", data[i].key);
//	}
//	printf("\n\n");
//
//	heap_sort(data, MAX_ELEMENT);
//
//	printf("정렬데이터\n");
//	for (i = 0; i < MAX_ELEMENT; i++)
//	{
//		if (i % 10 == 0 && i != 0)
//			printf("\n");
//		printf("%2d  ", data[i].key);
//	}
//
//	printf("\n\ncount : %d\n", count);
//
//	return 0;
//}