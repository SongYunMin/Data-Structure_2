#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ========= ���� ť =========

#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;

// Queue Type
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ
void init_queue(QueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

// ���� ���� ���� �Լ�
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


// delete Method
element dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("Queue is Empty");
	}
	// '%' ���� Queue
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return q->data[q->front];
}

void level_order(TreeNode* ptr)
{
	QueueType q;

	init_queue(&q);
	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		// Root �� Queue���� ������ �����
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		// Root�� �ڽ� �¿� �ڽĵ��� Enqueue ��.
		if (ptr->left) {
			enqueue(&q, ptr->left);
		}
		if (ptr->right) {
			enqueue(&q, ptr->right);
		}
	}
}

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2,&n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("���� ��ȸ");
	level_order(root);
	printf("\n");
	return 0;
}