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
//// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//// 삽입 함수
//void insert_max_heap(HeapType* h, element item)
//{
//	int i;
//	i = ++(h->heap_size);
//
//	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
//	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
//		h->heap[i] = h->heap[i / 2];
//		i /= 2;
//	}
//	h->heap[i] = item;
//}
//
//// 삭제 함수
//element delete_max_heap(HeapType* h)
//{
//	int parent, child;
//	element item, temp;
//
//	// 1 : 30, 2 : 5
//	item = h->heap[1];		// 루트 노드 대입
//	// 1 : 5
//	temp = h->heap[(h->heap_size)--]; // 마지막 노드 가져옴
//	parent = 1;		// 1 : 30
//	child = 2;		// 2 : 10
//
//	while (child <= h->heap_size) {
//		//h->heap_size--;
//		// 현재 노드의 자식 노드 중 더 큰 자식노드를 찾음
//		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
//			child++;
//		if (temp.key >= h->heap[child].key) break;
//		// 한 단계 아래로 이동
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