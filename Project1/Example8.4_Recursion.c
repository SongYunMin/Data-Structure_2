//#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//} TreeNode;
//
//#define SIZE 100
//int top = -1;
//
//TreeNode* stack[SIZE];
//
//void push(TreeNode* p)
//{
//	if (top < SIZE - 1) {
//		stack[++top] = p;
//	}
//}
//
//TreeNode* pop()
//{
//	TreeNode* p = NULL;
//	if (top >= 0) {
//		p = stack[top--];
//	}
//	return p;
//}
//
//void inorder_iter(TreeNode* root)
//{
//	while (1) {
//		// 왼쪽요소를 쭉 Push
//		for (; root; root = root->left) {
//			push(root);
//		}
//		// 하나씩 꺼내서 출력
//		root = pop();
//		if (!root) break;
//		printf("[%d] ", root->data);
//		// 오른쪽에 값이 있는지 확인(NULL이여도 반복)
//		root = root->right;
//	}
//}
//
//TreeNode n1 = { 1, NULL ,NULL};
//TreeNode n2 = { 4, &n1 ,NULL };
//TreeNode n3 = { 16, NULL ,NULL };
//TreeNode n4 = { 25, NULL ,NULL };
//TreeNode n5 = { 20, &n3, &n4 };
//TreeNode n6 = { 15, &n2 ,&n5 };
//
//TreeNode* root = &n6;
//
//int main(void)
//{
//	printf("중위 순회 = ");
//	inorder_iter(root);
//	printf("\n");
//
//	return 0;
//}