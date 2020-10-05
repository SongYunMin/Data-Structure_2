#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ========= 원형 큐 =========

#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;

// Queue Type
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 큐 초기화
void init_queue(QueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// Queue Push Method
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("Queue is Full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

