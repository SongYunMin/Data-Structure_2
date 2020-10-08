// Binary Tree Search Program
/*
	Name : Song yun min
	StuNum : 20174624
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;						// Element Type ����
typedef struct TreeNode {					// TreeNode ����
	element key;
	struct TreeNode* left, * right;			// Link ����
}TreeNode;

// Making new Node
TreeNode* makeNode(int data)
{
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));	// TreeNode��ŭ �޸𸮸� �Ҵ���
	tmp->key = data;										// data�� �Ҵ��� Node�� ����
	// Link initialized
	tmp->left = NULL;										// ���� link �ʱ�ȭ
	tmp->right = NULL;										// ������ link �ʱ�ȭ
	return tmp;												// �ʱ�ȭ�� Node Return
}

// Node Insert(Recursive)
TreeNode* insertRecursive(TreeNode* node, int key)
{
	if (node == NULL) return makeNode(key); 				// Ʈ���� ������ �� ���ο� ��� Return
	// ��ȯ������ Ʈ���� ������
	if (key < node->key)									// ������ Data�� ��� Node�� Data������ �۴ٸ�
		node->left = insertRecursive(node->left, key);		// �������� ������
	else if (key > node->key)								// ������ Data�� ��� Node�� Data������ ũ�ٸ�
		node->right = insertRecursive(node->right, key);	// ���������� ������

	return node;											// ������ �Ϸ�� Node�� Return
}

// Node Insert(Loop)
TreeNode* insertLoop(TreeNode** node, int key)
{
	count++;
	TreeNode* p, *t, *newnode;							// TreeNode 3�� ����

	t = *node;											// Node�� traver Node
	p = NULL;											// Node 'p' �ʱ�ȭ

	while (t != NULL){									// Node 't'�� NULL�� ������ �ݺ�
		if (key == t->key)	return;						// Data�� 't' Node�� Data�� ���ٸ� Return
		p = t;											// Node 't'�� Node 'p'�� ����
		if (key < p->key)								// Data�� Node 'p' �� Data ���� �۴ٸ�
			t = p->left;								// �������� �̵�
		else 											// Data�� Node 'p' �� Data ���� ũ�ٸ�
			t = p->right;								// ���������� �̵�
	}

	newnode = (TreeNode*)malloc(sizeof(TreeNode));		// Memory Allocation
	if (newnode == NULL)								// newnode �� NULL�϶� return
		return;
	newnode->key = key;									// Data�� newnode�� Data(key) �� ����
	newnode->left = newnode->right = NULL;				// Link �ʱ�ȭ

	if (p != NULL)										// p �� NULL�� �ƴϸ鼭
		if (key < p->key)								// Data�� Node 'p'�� Data���� �۴ٸ�
			p->left = newnode;							// 'newnode'�� Node 'p'�� ���� node�� �̵�
		else 											// Data�� Node 'p'�� Data���� ũ�ٸ�
			p->right = newnode;							// 'newnode'�� Node 'p'�� ������ node�� �̵�
	else
		*node = newnode;								// newnode�� node�� ����
}

// Number of Total Nodes
int getNodeCount(TreeNode* node)
{
	int cnt = 0;										// Count ���� ����
	if (node != NULL) {									// node�� NULL�� �ƴ϶��
		cnt = 1 + getNodeCount(node->left) +			// ���� �ڽĳ�带 ��������� ��ȯ�ϸ� ������ ����
			getNodeCount(node->right);
	}

	return cnt;											// Count ���� Return
}

// Number of Terminal Nodes
int getLeafCount(TreeNode* node)
{
	int cnt = 0;										// Count ���� ����
	if (node != NULL) {									// node�� NULL�� �ƴ϶��
		if (node->left == NULL && node->right == NULL)	// Node�� ���� �ڽİ� ������ �ڽ��� NULL�̶��
			return 1;									// ����
		else
			cnt = getLeafCount(node->left) +			// ��������� �͹̳� ��带 Count
			getLeafCount(node->right);
	}
	return cnt;											// Return Count
}

// MAX���� ���ϴ� �޼ҵ�
int MAX(int a, int b)
{
	if (a >= b) return a;
	else return b;

	return 1;
}

// Number of Node Height
int getNodeHeight(TreeNode* node)
{
	int height = 0;									// ���̸� ������ ������ ����
	if (node != NULL) {								// Node�� NULL�� �ƴ϶��
		height = 1 + MAX(getNodeHeight(node->left), // ��������� ���� ����
			getNodeHeight(node->right));
	}
	return height;									// ���� ���� ���� Return
}

int main(void)
{
	// Node �� �ʿ��� ���� ����
	TreeNode* recursiveRoot = NULL, * loopRoot = NULL;
	// File Open And Exception Processing
	FILE* fp;
	clock_t start, finish;
	int data;							// Data buf
	double timeResult;					// ���� �ð��� ������ ����
	fp = fopen("data_3.txt", "rt");

	if (fp == NULL) {
		printf("File Not Found!!\n");
		exit(-1);
	}

	start = clock();								// �ð� ���� ����
	// ������ ������ ��ȯ�� ���� �Լ�
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);					// ������ �о���� ��ȯ�� ����
		recursiveRoot = insertRecursive(recursiveRoot, data);
	}
	finish = clock();								// �ð����� ��
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("��ȯ�� ���� �ҿ�ð� : \t%lf\n", timeResult);

	rewind(fp);										// File Pointer �ʱ�ȭ

	start = clock();								// �ð����� ����
	// ������ ������ �ݺ��� ���� �Լ�
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);					// ������ �Ҿ����
		insertLoop(&loopRoot, data);				// �ݺ��� ����
	}
	finish = clock();								// �ð����� ��
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�ݺ��� ���� �ҿ�ð� : \t%lf\n\n", timeResult);

	// ��� ����, ����, �ܸ������ ������ ��� ��
	printf("------------- ��ȯ�� ���� ��� --------------\n");
	printf("��ü ��� ���� : \t%d\n", getNodeCount(recursiveRoot));
	printf("����� ���� : \t\t%d\n", getNodeHeight(recursiveRoot));
	printf("�ܸ������ ���� : \t%d\n", getLeafCount(recursiveRoot));
	printf("\n");
	printf("------------- �ݺ��� ���� ��� --------------\n");
	printf("��ü ��� ���� : \t%d\n", getNodeCount(loopRoot));
	printf("����� ���� : \t\t%d\n", getNodeHeight(loopRoot));
	printf("�ܸ������ ���� : \t%d\n", getLeafCount(loopRoot));

	fclose(fp);

	return 0;
}