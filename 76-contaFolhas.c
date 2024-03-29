#include <stdio.h>
#include <stdlib.h>

typedef struct tNode
{
    int key;
    struct tNode *left, *right;
} Node;

typedef struct tBinarySearchTree
{
    Node *root;
} BinarySearchTree;

BinarySearchTree *createEmptyTree()
{
    BinarySearchTree *bst = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
    bst->root = NULL;
    return bst;
}

Node *createNode(int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node **root, int key)
{
    if (*root == NULL)
    {
        *root = createNode(key);
    }
    else if (key < (*root)->key)
    {
        insert(&(*root)->left, key);
    }
    else if (key > (*root)->key)
    {
        insert(&(*root)->right, key);
    }
}

int countLeaves(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    return countLeaves(node->left) + countLeaves(node->right);
}

int main()
{
    int n, key;
    scanf("%d", &n);

    BinarySearchTree *bst = createEmptyTree();

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(&(bst->root), key);
    }

    printf("%d\n", countLeaves(bst->root));

    return 0;
}
