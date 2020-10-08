// Binary Tree Search Program
/*
	Name : Song yun min
	StuNum : 20174624
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;						// Element Type 정의
typedef struct TreeNode {					// TreeNode 정의
	element key;
	struct TreeNode* left, * right;			// Link 선언
}TreeNode;

// Making new Node
TreeNode* makeNode(int data)
{
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));	// TreeNode만큼 메모리를 할당함
	tmp->key = data;										// data를 할당한 Node에 대입
	// Link initialized
	tmp->left = NULL;										// 왼쪽 link 초기화
	tmp->right = NULL;										// 오른쪽 link 초기화
	return tmp;												// 초기화된 Node Return
}

// Node Insert(Recursive)
TreeNode* insertRecursive(TreeNode* node, int key)
{
	if (node == NULL) return makeNode(key); 				// 트리가 공백일 시 새로운 노드 Return
	// 순환적으로 트리를 내려감
	if (key < node->key)									// 삽입할 Data가 대상 Node의 Data값보다 작다면
		node->left = insertRecursive(node->left, key);		// 왼쪽으로 내려감
	else if (key > node->key)								// 삽입할 Data가 대상 Node의 Data값보다 크다면
		node->right = insertRecursive(node->right, key);	// 오른쪽으로 내려감

	return node;											// 삽입이 완료된 Node를 Return
}

// Node Insert(Loop)
TreeNode* insertLoop(TreeNode** node, int key)
{
	count++;
	TreeNode* p, *t, *newnode;							// TreeNode 3개 선언

	t = *node;											// Node를 traver Node
	p = NULL;											// Node 'p' 초기화

	while (t != NULL){									// Node 't'가 NULL일 때까지 반복
		if (key == t->key)	return;						// Data가 't' Node의 Data와 같다면 Return
		p = t;											// Node 't'를 Node 'p'에 대입
		if (key < p->key)								// Data가 Node 'p' 의 Data 보다 작다면
			t = p->left;								// 왼쪽으로 이동
		else 											// Data가 Node 'p' 의 Data 보다 크다면
			t = p->right;								// 오른쪽으로 이동
	}

	newnode = (TreeNode*)malloc(sizeof(TreeNode));		// Memory Allocation
	if (newnode == NULL)								// newnode 가 NULL일때 return
		return;
	newnode->key = key;									// Data를 newnode의 Data(key) 로 대입
	newnode->left = newnode->right = NULL;				// Link 초기화

	if (p != NULL)										// p 가 NULL이 아니면서
		if (key < p->key)								// Data가 Node 'p'의 Data보다 작다면
			p->left = newnode;							// 'newnode'를 Node 'p'의 왼쪽 node로 이동
		else 											// Data가 Node 'p'의 Data보다 크다면
			p->right = newnode;							// 'newnode'를 Node 'p'의 오른쪽 node로 이동
	else
		*node = newnode;								// newnode를 node에 대입
}

// Number of Total Nodes
int getNodeCount(TreeNode* node)
{
	int cnt = 0;										// Count 변수 선언
	if (node != NULL) {									// node가 NULL이 아니라면
		cnt = 1 + getNodeCount(node->left) +			// 양쪽 자식노드를 재귀적으로 순환하며 갯수를 센다
			getNodeCount(node->right);
	}

	return cnt;											// Count 변수 Return
}

// Number of Terminal Nodes
int getLeafCount(TreeNode* node)
{
	int cnt = 0;										// Count 변수 선언
	if (node != NULL) {									// node가 NULL이 아니라면
		if (node->left == NULL && node->right == NULL)	// Node의 왼쪽 자식과 오른쪽 자식이 NULL이라면
			return 1;									// 종료
		else
			cnt = getLeafCount(node->left) +			// 재귀적으로 터미널 노드를 Count
			getLeafCount(node->right);
	}
	return cnt;											// Return Count
}

// MAX값을 구하는 메소드
int MAX(int a, int b)
{
	if (a >= b) return a;
	else return b;

	return 1;
}

// Number of Node Height
int getNodeHeight(TreeNode* node)
{
	int height = 0;									// 높이를 측정할 변수를 선언
	if (node != NULL) {								// Node가 NULL이 아니라면
		height = 1 + MAX(getNodeHeight(node->left), // 재귀적으로 높이 측정
			getNodeHeight(node->right));
	}
	return height;									// 높이 측정 변수 Return
}

int main(void)
{
	// Node 및 필요한 변수 선언
	TreeNode* recursiveRoot = NULL, * loopRoot = NULL;
	// File Open And Exception Processing
	FILE* fp;
	clock_t start, finish;
	int data;							// Data buf
	double timeResult;					// 수행 시간을 측정할 변수
	fp = fopen("data_3.txt", "rt");

	if (fp == NULL) {
		printf("File Not Found!!\n");
		exit(-1);
	}

	start = clock();								// 시간 측정 시작
	// 파일을 읽으며 순환적 삽입 함수
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);					// 파일을 읽어오고 순환적 삽입
		recursiveRoot = insertRecursive(recursiveRoot, data);
	}
	finish = clock();								// 시간측정 끝
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("순환적 삽입 소요시간 : \t%lf\n", timeResult);

	rewind(fp);										// File Pointer 초기화

	start = clock();								// 시간측정 시작
	// 파일을 읽으며 반복적 삽입 함수
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);					// 파일을 잃어오고
		insertLoop(&loopRoot, data);				// 반복적 삽입
	}
	finish = clock();								// 시간측정 끝
	timeResult = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("반복적 삽입 소요시간 : \t%lf\n\n", timeResult);

	// 노드 갯수, 높이, 단말노드의 갯수를 출력 함
	printf("------------- 순환적 삽입 결과 --------------\n");
	printf("전체 노드 갯수 : \t%d\n", getNodeCount(recursiveRoot));
	printf("노드의 높이 : \t\t%d\n", getNodeHeight(recursiveRoot));
	printf("단말노드의 갯수 : \t%d\n", getLeafCount(recursiveRoot));
	printf("\n");
	printf("------------- 반복적 삽입 결과 --------------\n");
	printf("전체 노드 갯수 : \t%d\n", getNodeCount(loopRoot));
	printf("노드의 높이 : \t\t%d\n", getNodeHeight(loopRoot));
	printf("단말노드의 갯수 : \t%d\n", getLeafCount(loopRoot));

	fclose(fp);

	return 0;
}