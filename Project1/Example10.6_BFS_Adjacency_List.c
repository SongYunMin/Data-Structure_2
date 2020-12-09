//#include <stdio.h>
//#include <stdlib.h>
//
//#define TRUE 1
//#define FALSE 0
//#define MAX_QUEUE_SIZE 10
//#define MAX_VERTICES 50
//
//typedef struct GraphNode {
//	int vertex;
//	struct GraphNode* link;
//} GraphNode;
//
//typedef struct GraphType {
//	int n;	// ������ ����
//	GraphNode* adj_list[MAX_VERTICES];
//} GraphType;
//
//int visited[MAX_VERTICES];
//
//typedef int element;
//
//// ť Ÿ��
//typedef struct {
//	element queue[MAX_QUEUE_SIZE];
//	int front, rear;
//} QueueType;
//
//// ���� �Լ�
//void error(char* message)
//{
//	printf("%s\n", message);
//	exit(-1);
//}
//
//// ť �ʱ�ȭ �Լ�
//void queue_init(QueueType* q)
//{
//	q->front = 0;
//	q->rear = 0;
//}
//
//// ���� ���� ���� �Լ�
//int is_empty(QueueType* q)
//{
//	return (q->front == q->rear);
//}
//
//// ��ȭ ���� ���� �Լ�
//int is_full(QueueType* q)
//{
//	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
//}
//
//// ���� �Լ�
//void enqueue(QueueType* q, element item)
//{
//	if (is_full(q)) {
//		error("ť�� ��ȭ���� �Դϴ�.\n");
//	}
//	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//	q->queue[q->rear] = item;
//}
//
//// ���� �Լ�
//element dequeue(QueueType* q)
//{
//	if (is_empty(q)) {
//		error("ť�� ������� �Դϴ�.\n");
//	}
//	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//	return q->queue[q->front];
//}
//
//// �׷��� �ʱ�ȭ
//void init(GraphType* g)
//{
//	int v;
//	g->n = 0;
//	for (v = 0; v < MAX_VERTICES; v++) {
//		g->adj_list[v] = NULL;
//	}
//}
//
//// ���� ���� ����
//void insert_vertex(GraphType* g, int v)
//{
//	if (((g->n) + 1) > MAX_VERTICES) {
//		printf("�׷��� : ������ ���� �ʰ�\n");
//		return -1;
//	}
//	g->n++;
//}
//
//// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
//void insert_edge(GraphType* g, int u, int v)
//{
//	GraphNode* node;
//	if (u >= g->n || v >= g->n) {
//		printf("�׷��� : ���� ��ȣ ����\n");
//		return -1;
//	}
//	// �����Ҵ�
//	node = (GraphNode*)malloc(sizeof(GraphNode));
//	node->vertex = v;
//	node->link = g->adj_list[u];
//	g->adj_list[u] = node;
//}
//
//void bfs_list(GraphType* g, int v)
//{
//	GraphNode* w;
//	QueueType q;
//
//	queue_init(&q);				// ť �ʱ�ȭ
//	visited[v] = TRUE;		// ���� v �湮 ǥ��
//	printf("%d �湮 -> ", v);
//	enqueue(&q, v);
//	while (!is_empty(&q)) {
//		v = dequeue(&q);	// ť�� ����� ���� ����
//		// ���� ���� Ž��
//		for (w = g->adj_list[v]; w; w = w->link) {
//			if (!visited[w->vertex]) {				// �̹湮 ���� Ž��
//				visited[w->vertex] = TRUE;			// �湮 ǥ��
//				printf("%d �湮 -> ", w->vertex);
//				enqueue(&q, w->vertex);				// ������ ť�� ����
//			}
//		}
//	}
//}
//
//
//int main(void)
//{
//	GraphType* g;
//	QueueType q;
//	g = (GraphType*)malloc(sizeof(GraphType));
//
//	init(g);
//
//	for (int i = 0; i < 6; i++) {
//		insert_vertex(g, i);
//	}
//
//	insert_edge(g, 0, 2);
//	insert_edge(g, 2, 1);
//	insert_edge(g, 2, 3);
//	insert_edge(g, 0, 4);
//	insert_edge(g, 4, 5);
//	insert_edge(g, 1, 5);
//
//	printf("BFS\n");
//	bfs_list(g, 0);
//	printf("\n");
//	free(g);
//
//	return 0;
//}