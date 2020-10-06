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

// Making new Node
TreeNode* makeNode(int data)
{
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = data;
	// Link initialized
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

TreeNode* insertRecursive(TreeNode* node, int key)
{
	// 트리가 공백일 시 새로운 노드 Return
	if (node == NULL) return makeNode(key);
	// 순환적으로 트리를 내려감
	if (key < node->key)
		node->left = insertRecursive(node->left, key);
	else if (key > node->key)
		node->right = insertRecursive(node->right, key);

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

int MAX(int a, int b)
{
	if (a >= b) return a;
	else return b;

	return 1;
}

// Number of Node Height
int getNodeHeight(TreeNode* node)
{
	int height = 0;
	if (node != NULL) {
		height = 1 + MAX(getNodeHeight(node->left), getNodeHeight(node->right));
	}
	return height;
}

int main(void)
{
	TreeNode* recursiveRoot = NULL, * loopRoot = NULL;
	// File Open And Exception Processing
	FILE* fp;
	clock_t start, finish;
	int data;
	double timeResult;
	fp = fopen("data_3.txt", "rt");

	if (fp == NULL) {
		printf("File Not Found!!\n");
		exit(-1);
	}
	start = clock();
	// 파일을 읽으며 순환적 삽입 함수
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
		recursiveRoot = insertRecursive(recursiveRoot, data);
	}
	finish = clock();
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("순환적 삽입 소요시간 : \t%lf\n", timeResult);

	rewind(fp);

	/*
		반복적 삽입 함수 정의
	*/

	printf("전체 노드 갯수 : \t%d\n", getNodeCount(recursiveRoot));
	printf("노드의 높이 : \t\t%d\n", getNodeHeight(recursiveRoot));
	printf("단말노드의 갯수 : \t%d\n", getLeafCount(recursiveRoot));

	return 0;
}