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
//// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환
//TreeNode* delete_node(TreeNode* root, element key)
//{
//    if (root == NULL) return root;
//    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
//    if (compare(key, root->key) < 0)
//        root->left = delete_node(root->left, key);
//    // 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
//    if (compare(key, root->key) > 0)
//        root->right = delete_node(root->right, key);
//    // 키가 루트와 같으면 이 노드를 삭제하면 됨
//    else
//    {
//        // 첫 번째나 두 번째의 경우
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
//        // 세 번째 경우
//        TreeNode* temp = min_value_node(root->right);
//
//        //중위 순회시 후계 노드를 복사한다.
//        root->key = temp->key;
//        //중위 순회시 후계 노드를 삭제한다.
//        root->right = delete_node(root->right, temp->key);
//    }
//    return root;
//}
//
////
//void help(void)
//{
//    printf("\n**** i : 입력, d : 삭제, s : 탐색, p : 출력, q : 종료 **** : ");
//}
//
//// 이진 탐색 트리를 사용하는 영어 사전 프로그램
//int main(void)
//{
//    char command;
//    element e;
//    TreeNode* root = NULL;
//    TreeNode* temp;
//    do {
//        help();
//        command = getchar();
//        getchar();   // 입력 버퍼 제거
//        switch (command)
//        {
//        case 'i':
//            printf("단어 : ");
//            gets(e.word);
//            printf("의미 : ");
//            gets(e.meaning);
//            root = insert_node(root, e);
//            break;
//        case 'd':
//            printf("단어 : ");
//            gets(e.word);
//            root = delete_node(root, e);
//            break;
//        case 'p':
//            display(root);
//            printf("\n");
//            break;
//        case 's':
//            printf("단어 : ");
//            gets(e.word);
//            temp = search(root, e);
//            if (temp != NULL)
//                printf("의미 : %s\n", e.meaning);
//            break;
//        default:
//            break;
//        }
//    } while (command != 'q');
//    return 0;
//}