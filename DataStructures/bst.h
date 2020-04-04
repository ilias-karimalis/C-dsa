#ifndef BST_H
#define BST_H

#define NULL ((void*) 0)

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* node_init(int value);
Node* bst_insert(Node* bst, int value);
Node* bst_remove(Node* bst, int value);
Node* bst_find(Node* bst, int value);
void bst_inorder(Node* bst);
void bst_delete(Node* bst);
Node* bst_minValueNode(Node* bst);

#endif
