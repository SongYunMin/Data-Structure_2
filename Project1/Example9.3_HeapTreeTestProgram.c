//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_ELEMENT 200
//
//typedef struct {
//	int key;
//} element;
//typedef struct {
//	element heap[MAX_ELEMENT];
//	int heap_size;
//} HeapType;
//
//// Create Method
//HeapType* create()
//{
//	return (HeapType*)malloc(sizeof(HeapType));
//}
//
//// initialize Method
//void init(HeapType* h)
//{
//	h->heap_size = 0;
//}
//
//// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
//// ���� �Լ�
//void insert_max_heap(HeapType* h, element item)
//{
//	int i;
//	i = ++(h->heap_size);
//
//	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
//	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//	h->heap[i] = item;
//}
//
//// ���� �Լ�
//element delete_max_heap(HeapType* h)
//{
//	int parent, child;
//	element item, temp;
//
//	// 1 : 30, 2 : 5
//	item = h->heap[1];		// ��Ʈ ��� ����
//	// 1 : 5
//	temp = h->heap[(h->heap_size)--]; // ������ ��� ������
//	parent = 1;		// 1 : 30
//	child = 2;		// 2 : 10
//
//	while (child <= h->heap_size) {
//		//h->heap_size--;
//		// ���� ����� �ڽ� ��� �� �� ū �ڽĳ�带 ã��
//		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
//			child++;
//		if (temp.key >= h->heap[child].key) break;
//		// �� �ܰ� �Ʒ��� �̵�
//		h->heap[parent] = h->heap[child];
//		parent = child;
//		child *= 2;
//		}
//	h->heap[parent] = temp;
//	return item;
//}
//
//int main(void)
//{
//	element e1 = { 10 }, e2 = { 40 }, e3 = { 30 }, e4 = { 5 }, e5 = { 12 }, e6 = { 6 }, e7 = {15};
//	element e8 = { 9 }, e9 = { 60 };
//	element r1, r2, r3, r4, r5, r6, r7, r8, r9;
//	HeapType* heap;
//
//	heap = create();
//	init(heap);
//
//	// insert
//	insert_max_heap(heap, e1);
//	insert_max_heap(heap, e2);
//	insert_max_heap(heap, e3);
//	insert_max_heap(heap, e4);
//	insert_max_heap(heap, e5);
//	insert_max_heap(heap, e6);
//	insert_max_heap(heap, e7);
//	insert_max_heap(heap, e8);
//	insert_max_heap(heap, e9);
//
//
//	// Delete
//	e4 = delete_max_heap(heap);
//	printf("< %d > ", e4.key);
//
//	e5 = delete_max_heap(heap);
//	printf("< %d > ", e5.key);
//
//	e6 = delete_max_heap(heap);
//	printf("< %d > ", e6.key);
//
//	free(heap);
//
//	return 0;
//}