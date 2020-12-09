#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];	// 부모 노드

// 초기화
void set_init(int n)
{
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
}

// curr가 속하는 집합을 반환함
int set_find(int curr)
{
	if (parent[curr] == -1) {
		return curr;
	}
	while(parent[curr] != -1) curr = parent[curr]
;}