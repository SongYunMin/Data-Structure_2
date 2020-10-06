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
	if (node == NULL) return NULL;					// node�� ��������� ����
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
	return NULL;		// Ž���� �������� ���
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
	// Ʈ���� ������ �� ���ο� ��� Return
	if (node == NULL) return makeNode(key);

	// ��ȯ������ Ʈ���� ������
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

	// ������ ������ ��ȯ�� Ž�� �Լ� ����
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
	}


	return 0;
}