#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

void insert_node_loop(TreeNode** root, int key)
{
	TreeNode* parent, * traverse, * newNode;

	traverse = *root;
	parent = NULL;

	while (traverse != NULL)
	{
		if (key == traverse->key) return;

		parent = traverse;
		if (key < parent->key)
			traverse = parent->left;
		else
			traverse = parent->right;
	}

	////////////////////////////////////////////////
	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (newNode == NULL)
		return;
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	////////////////////////////////////////////////


	if (parent != NULL)
		if (key < parent->key)
			parent->left = newNode;
		else
			parent->right = newNode;
	else
		*root = newNode;
}

TreeNode* new_node(int key)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	return newNode;
}

TreeNode* insert_node_recursive(TreeNode* node, int key)
{
	if (node == NULL)
		return new_node(key);
	if (key < node->key)
		node->left = insert_node_recursive(node->left, key);
	else
		node->right = insert_node_recursive(node->right, key);

	return node;
}

int MAX(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;

	return 1;
}

int get_height(TreeNode* node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));

	return height;
}

int get_leaf_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}

	return count;
}

int get_node_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

int main(void)
{
	FILE* fp = NULL;
	TreeNode* rootRecursive = NULL, * rootLoop = NULL;
	TreeNode* temp;
	clock_t start, finish;
	long double duration;
	int item;

	fp = fopen("data_3.txt", "rt");


	start = clock();
	while (!feof(fp))
	{
		fscanf(fp, "%d", &item);

		rootRecursive = insert_node_recursive(rootRecursive, item);
	}
	finish = clock();
	duration = (long double)(finish - start) / CLOCKS_PER_SEC;
	printf("��ȯȣ��� ���� �Ϸ�\n");
	printf("�ɸ� �ð� : %llf\n", duration);

	rewind(fp);

	start = clock();
	while (!feof(fp))
	{
		fscanf(fp, "%d", &item);

		insert_node_loop(&rootLoop, item);
	}
	finish = clock();
	duration = (long double)(finish - start) / CLOCKS_PER_SEC;
	printf("�ݺ����� ���� �Ϸ�\n");
	printf("�ɸ� �ð� : %llf\n", duration);

	printf("������ Ʈ���� ��ü ��� ���� : %d\n", get_node_count(rootRecursive));
	printf("������ Ʈ���� ��ü ��� ���� : %d\n", get_node_count(rootLoop));

	printf("Ʈ���� ���� : %d\n", get_height(rootRecursive));
	printf("Ʈ���� ���� : %d\n", get_height(rootLoop));

	printf("�ܸ� ����� ���� : %d\n", get_leaf_count(rootRecursive));
	printf("�ܸ� ����� ���� : %d\n", get_leaf_count(rootLoop));

	fclose(fp);
	return 0;
}