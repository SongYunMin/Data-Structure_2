//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <memory.h>
//
//#define MAX_WORD_SIZE      100
//#define MAX_MEANING_SIZE   200
//
//// data form
//typedef struct {
//    char word[MAX_WORD_SIZE];   // key field
//    char meaning[MAX_MEANING_SIZE];
//}element;
//
//// node structure
//typedef struct TreeNode {
//    element key;
//    TreeNode* left, * right;
//}TreeNode;
//
//// if e1 < e2, return -1
//// if e1 == e2, return 0
//// if e1 > e2, return 1
//int compare(element e1, element e2)
//{
//    return strcmp(e1.word, e2.word);
//}
//
//// print binary tree function
//void display(TreeNode* p)
//{
//    if (p != NULL) {
//        printf("(");
//        display(p->left);
//        printf("%s : %s", p->key.word, p->key.meaning);
//        display(p->right);
//        printf(")");
//    }
//}
//
//// search binary tree function
//TreeNode* search(TreeNode* root, element key)
//{
//    TreeNode* p = root;
//    while (p != NULL) {
//        if (compare(key, p->key) == 0)
//            return p;
//        else if (compare(key, p->key) < 0)
//            p = p->left;
//        else if (compare(key, p->key) > 0)
//            p = p->right;
//    }
//    return p;
//} // if fail the search than return NULL
//
//TreeNode* new_node(element item)
//{
//    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
//    temp->key = item;
//    temp->left = temp->right = NULL;
//    return temp;
//}
//
//TreeNode* insert_node(TreeNode* node, element key)
//{
//    // if tree node is empty than return new node
//    if (node == NULL) return new_node(key);
//
//    // else recursive tree call
//    if (compare(key, node->key) < 0)
//        node->left = insert_node(node->left, key);
//    else if (compare(key, node->key) > 0)
//        node->right = insert_node(node->right, key);
//
//    return node;
//}
//
//TreeNode* min_value_node(TreeNode* node)
//{
//    TreeNode* current = node;
//    // to find most left end node
//    while (current->left != NULL)
//        current = current->left;
//
//    return current;
//}
//
//// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� ���ο� ��Ʈ ��带 ��ȯ
//TreeNode* delete_node(TreeNode* root, element key)
//{
//    if (root == NULL) return root;
//    // ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
//    if (compare(key, root->key) < 0)
//        root->left = delete_node(root->left, key);
//    // ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
//    if (compare(key, root->key) > 0)
//        root->right = delete_node(root->right, key);
//    // Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
//    else
//    {
//        // ù ��°�� �� ��°�� ���
//        if (root->left == NULL) {
//            TreeNode* temp = root->right;
//            free(root);
//            return temp;
//        }
//        else if (root->right == NULL) {
//            TreeNode* temp = root->left;
//            free(root);
//            return temp;
//        }
//        // �� ��° ���
//        TreeNode* temp = min_value_node(root->right);
//
//        //���� ��ȸ�� �İ� ��带 �����Ѵ�.
//        root->key = temp->key;
//        //���� ��ȸ�� �İ� ��带 �����Ѵ�.
//        root->right = delete_node(root->right, temp->key);
//    }
//    return root;
//}
//
////
//void help(void)
//{
//    printf("\n**** i : �Է�, d : ����, s : Ž��, p : ���, q : ���� **** : ");
//}
//
//// ���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷�
//int main(void)
//{
//    char command;
//    element e;
//    TreeNode* root = NULL;
//    TreeNode* temp;
//    do {
//        help();
//        command = getchar();
//        getchar();   // �Է� ���� ����
//        switch (command)
//        {
//        case 'i':
//            printf("�ܾ� : ");
//            gets(e.word);
//            printf("�ǹ� : ");
//            gets(e.meaning);
//            root = insert_node(root, e);
//            break;
//        case 'd':
//            printf("�ܾ� : ");
//            gets(e.word);
//            root = delete_node(root, e);
//            break;
//        case 'p':
//            display(root);
//            printf("\n");
//            break;
//        case 's':
//            printf("�ܾ� : ");
//            gets(e.word);
//            temp = search(root, e);
//            if (temp != NULL)
//                printf("�ǹ� : %s\n", e.meaning);
//            break;
//        default:
//            break;
//        }
//    } while (command != 'q');
//    return 0;
//}