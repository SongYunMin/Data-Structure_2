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
//	int n;	// ������ ����
//	GraphNode* adj_list[MAX_VERTICES];
//} GraphType;
//
//int visited[MAX_VERTICES];
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
//// ���� ��ķ� ǥ���� �׷����� ���� ���� �켱 Ž��
//void dfs_list(GraphType* g, int v)
//{
//	GraphNode* w;
//	visited[v] = TRUE;						// ���� v�� �湮�� ǥ��
//	printf("���� %d -> ", v);				// �湮�� ���� ���
//	for (w = g->adj_list[v]; w; w = w->link) {	// ���� ���� Ž��
//		if (!visited[w->vertex]) {
//			dfs_list(g, w->vertex);				// ���� w���� DFS ���� ����
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