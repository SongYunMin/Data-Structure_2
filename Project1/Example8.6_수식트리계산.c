#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* exp = &n7;

// 수식 계산 함수
int evaluate(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)		// 양쪽 node가 NULL이면
		return root->data;								// 데이터를 return
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf(" %d %c %d을 계산합니다.\n ", op1, root->data, op2);
		switch (root->data)
		{
		case '+': op1 + op2;
		case '-': op1 - op2;
		case '*': op1 * op2;
		case '/': op1 / op2;
		default:
			break;
		}
	}
	return 0;
}

int main(void)
{
	printf("수식의 값은 %d입니다.\n", evaluate(exp));

	return 0;
}