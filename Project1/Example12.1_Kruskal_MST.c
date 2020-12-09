#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];	// �θ� ���

// �ʱ�ȭ
void set_init(int n)
{
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
}

// curr�� ���ϴ� ������ ��ȯ��
int set_find(int curr)
{
	if (parent[curr] == -1) {
		return curr;
	}
	while(parent[curr] != -1) curr = parent[curr]
;}