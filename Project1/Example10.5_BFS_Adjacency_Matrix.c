#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;

// 큐 타입
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	printf("%s\n", message);
	exit(-1);
}

// 큐 초기화 함수
void queue_init(QueueType* q)
{
	q->front = 0;
	q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		error("큐가 포화상태 입니다.\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q)){
		error("큐가 공백상태 입니다.\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// 정점의 갯수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

// 그래프 초기화
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

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		error("그래프 : 정점의 갯수 초과");
		exit(-1);
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		error("그래프 : 정점 번호 오류");
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

	queue_init(&q);			// 큐 초기화
	visited[v] = TRUE;		// 정점 v 방문
	printf("%d 방문 -> ", v);
	enqueue(&q, v);			// 시작 정점을 큐에 저장
	while (!is_empty(&q)) {
		v = dequeue(&q);	// 큐의 정점 추출
		for (w = 0; w < g->n; w++) {	// 인접 정점 탐색
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;		// 방문 표시
				printf("%d 방문 -> ", w);
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