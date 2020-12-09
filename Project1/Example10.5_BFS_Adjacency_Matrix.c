#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;

// ť Ÿ��
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	printf("%s\n", message);
	exit(-1);
}

// ť �ʱ�ȭ �Լ�
void queue_init(QueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		error("ť�� ��ȭ���� �Դϴ�.\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q)){
		error("ť�� ������� �Դϴ�.\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

// �׷��� �ʱ�ȭ
void graph_init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;
		}
	}
}

// ���� ���� ����
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		error("�׷��� : ������ ���� �ʰ�");
		exit(-1);
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		error("�׷��� : ���� ��ȣ ����");
		exit(-1);
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

// BFS
void bfs_mat(GraphType* g, int v)
{
	int w;
	QueueType q;

	queue_init(&q);			// ť �ʱ�ȭ
	visited[v] = TRUE;		// ���� v �湮
	printf("%d �湮 -> ", v);
	enqueue(&q, v);			// ���� ������ ť�� ����
	while (!is_empty(&q)) {
		v = dequeue(&q);	// ť�� ���� ����
		for (w = 0; w < g->n; w++) {	// ���� ���� Ž��
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;		// �湮 ǥ��
				printf("%d �湮 -> ", w);
				enqueue(&q, w);
			}
		}
	}
}

int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	for (int i = 0; i < 6; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("BFS\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);

	return 0;
}