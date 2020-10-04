//#include <stdio.h>
//#include <stdlib.h>
//
//// Data And Link Node
//typedef struct NodeStruct
//{
//    int value;
//    struct NodeStruct* leftChild;
//    struct NodeStruct* rightChild;
//}Node;
//
//Node* root = NULL;
//
//// Data Insert Function
//Node* BST_insert(Node* root, int value)
//{
//    if (root == NULL)
//    {
//        root = (Node*)malloc(sizeof(Node));
//        root->leftChild = root->rightChild = NULL;
//        root->value = value;
//        return root;
//    }
//    else
//    {
//        if (root->value > value)
//            root->leftChild = BST_insert(root->leftChild, value);
//        else
//            root->rightChild = BST_insert(root->rightChild, value);
//    }
//    return root;
//}
//
//Node* findMinNode(Node* root)
//{
//    Node* tmp = root;
//    while (tmp->leftChild != NULL)
//        tmp = tmp->leftChild;
//    return tmp;
//}
//
//// Node Delete Function
//Node* BST_delete(Node* root, int value)
//{
//    Node* tNode = NULL;
//    if (root == NULL)
//        return NULL;
//
//    if (root->value > value)
//        root->leftChild = BST_delete(root->leftChild, value);
//    else if (root->value < value)
//        root->rightChild = BST_delete(root->rightChild, value);
//    else
//    {
//        // 자식 노드가 둘 다 있을 경우
//        if (root->rightChild != NULL && root->leftChild != NULL)
//        {
//            tNode = findMinNode(root->rightChild);
//            root->value = tNode->value;
//            root->rightChild = BST_delete(root->rightChild, tNode->value);
//        }
//        else
//        {
//            tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
//            free(root);
//            return tNode;
//        }
//
//    }
//    return root;
//}
//
//
//// Data Search Function
//Node* BST_search(Node* root, int value)
//{
//    if (root == NULL)
//        return NULL;
//
//    if (root->value == value)
//        return root;
//    else if (root->value > value)
//        return BST_search(root->leftChild, value);
//    else
//        return BST_search(root->rightChild, value);
//}
//void BST_print(Node* root)
//{
//    if (root == NULL)
//        return;
//
//    printf("%d ", root->value);
//    BST_print(root->leftChild);
//    BST_print(root->rightChild);
//}
//
//int main()
//{
//    root = BST_insert(root, 3);
//    root = BST_insert(root, 2);
//    root = BST_insert(root, 1);
//    root = BST_insert(root, 4);
//    root = BST_insert(root, 5);
//    root = BST_insert(root, 6);
//
//    // Delete Root
//    root = BST_delete(root, 6);
//
//    BST_print(root);
//}