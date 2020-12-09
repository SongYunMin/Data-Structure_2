//#include <stdio.h>
//#include <stdlib.h>
//
//#define TRUE 1
//#define FALSE 0
//#define MAX_VERTICES 50
//
//typedef struct GraphNode {
//	int vertex;
//	struct GraphNode* link;
//} GraphNode;
//
//typedef struct GraphType {
//	int n;	// 정점의 갯수
//	GraphNode* adj_list[MAX_VERTICES];
//} GraphType;
//
//int visited[MAX_VERTICES];
//
//// 그래프 초기화
//void init(GraphType* g)
//{
//	int v;
//	g->n = 0;
//	for (v = 0; v < MAX_VERTICES; v++) {
//		g->adj_list[v] = NULL;
//	}
//}
//
//// 정점 삽입 연산
//void insert_vertex(GraphType* g, int v)
//{
//	if (((g->n) + 1) > MAX_VERTICES) {
//		printf("그래프 : 정점의 갯수 초과\n");
//		return -1;
//	}
//	g->n++;
//}
//
//// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
//void insert_edge(GraphType* g, int u, int v)
//{
//	GraphNode* node;
//	if (u >= g->n || v >= g->n) {
//		printf("그래프 : 정점 번호 오류\n");
//		return -1;
//	}
//	// 동적할당
//	node = (GraphNode*)malloc(sizeof(GraphNode));
//	node->vertex = v;
//	node->link = g->adj_list[u];
//	g->adj_list[u] = node;
//}
//
//// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
//void dfs_list(GraphType* g, int v)
//{
//	GraphNode* w;
//	visited[v] = TRUE;						// 정점 v의 방문을 표시
//	printf("정점 %d -> ", v);				// 방문한 정점 출력
//	for (w = g->adj_list[v]; w; w = w->link) {	// 인접 정점 탐색
//		if (!visited[w->vertex]) {
//			dfs_list(g, w->vertex);				// 정점 w에서 DFS 새로 시작
//		}
//	}
//}
//
//int main(void)
//{
//	GraphType* g;
//	g = (GraphType*)malloc(sizeof(GraphType));
//	init(g);
//
//	for (int i = 0; i < 4; i++) {
//		insert_vertex(g, i);
//	}
//
//	insert_edge(g, 0, 1);
//	insert_edge(g, 0, 2);
//	insert_edge(g, 0, 3);
//	insert_edge(g, 1, 2);
//	insert_edge(g, 2, 3);
//
//	printf("DFS\n");
//	dfs_list(g, 0);
//	printf("\n");
//	free(g);
//
//	return 0;
//}