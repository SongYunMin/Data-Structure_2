// Binary Tree Search Program
/*
	Name : Song yun min
	StuNum : 20174624
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// Recursive Searching Function
TreeNode* recursiveSearch(TreeNode* node, int key)
{
	if (node == NULL) return NULL;					// node가 비어있으면 종료
	if (key == node->key) return node;
	else if (key < node->key)
		return recursiveSearch(node->left, key);
	else
		return recursiveSearch(node->right, key);
}

// Repetitive Searching Function
TreeNode* loopSearch(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;		// 탐색에 실패했을 경우
}

TreeNode* makeNode(int data)
{
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = data;
	// Link initialized
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

TreeNode* insertLoop(TreeNode* node, int key)
{
	// 트리가 공백일 시 새로운 노드 Return
	if (node == NULL) return makeNode(key);

	// 순환적으로 트리를 내려감
	if (key < node->key)
		node->left = insertLoop(node->left, key);
	else if (key > node->key)
		node->right = insertLoop(node->right, key);

	return node;
}



// Number of Total Nodes
int getNodeCount(TreeNode* node)
{
	int cnt = 0;
	if (node != NULL) {
		cnt = 1 + getNodeCount(node->left) + getNodeCount(node->right);
	}

	return cnt;
}

// Number of Terminal Nodes
int getLeafCount(TreeNode* node)
{
	int cnt = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			cnt = getLeafCount(node->left) + getLeafCount(node->right);
	}
	return cnt;
}

// Number of Node Height
int getNodeHeight(TreeNode* node)
{
	int height = 0;
	if (node != NULL) {
		height = 1 + max(getNodeHeight(node->left), getNodeHeight(node->right));
	}
}

int main(void)
{
	// File Open And Exception Processing
	FILE* fp;
	int data;
	fp = fopen("data_3.txt", "rt");

	if (fp == NULL) {
		printf("File Not Found!!\n");
		exit(-1);
	}

	// 파일을 읽으며 순환적 탐색 함수 삽입
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
	}


	return 0;
}