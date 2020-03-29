#include "stack.h"

#define NULL ((void*) 0)

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* node_init(int value);
void bst_insert(Node* bst, int value);
void bst_remove(Node* bst, int value);
Node* bst_find(Node* bst, int value);
void bst_inorder(Node* bst);
void bst_delete(Node* bst);
Node* bst_minValueNode(Node* bst);

Node* node_init(int value) {
    Node* res = malloc(sizeof(Node));
    res->value = value;
    res->left = res->right = NULL;
    return res;
}

void bst_insert(Node* bst, int value) {
    if (bst == NULL) {
        bst = node_init(value);
    } else {
        if (bst->value > value) {
            bst_insert(bst->left, value);
        } else if (bst->value < value) {
            bst_insert(bst->right, value);
        }
    }
}

Node* bst_find(Node* bst, int value) {
    if (!bst) {
        return NULL;
    } else {
        if (bst->value == value) {
            return bst;
        } else if (bst->value > value) {
            return bst_find(bst->left, value);
        } else {
            return bst_find(bst->right, value);
        }
    }
}

void bst_inorder(Node* bst) {
    if (root) {
        bst_inorder(bst->left);
        printf("%d \n", bst->key);
        bst_inorder(bst->right);
    }
}

Node* bst_remove(Node* bst, int value) {
    if (!root) {
        return root;
    } else if (bst->value > value) {
        bst->left = bst_remove(bst->left, value);
    } else if (bst->value < value) {
        bst->right = bst_remove(bst->right, value);
    } else {
        if (!bst->left) {
            Node* temp = root->right;
            free(bst);
            return temp;
        } else if (!bst->right) {
            Node* temp = root->left;
            free(bst);
            return temp;
        } else {
            Node* temp = bst_minValueNode(bst->right);
            bst->value = temp->value;
            bst->right = bst_remove(bst->right, temp->value);
        }
    }
    return bst;
}

Node* bst_minValueNode(Node* bst) {
    Node* curr = bst;
    while(curr && curr->left)
        curr = curr->left;
    return curr;
}

void bst_delete(Node* bst) {
    if (bst) {
        bst_delete(bst->left);
        bst_delete(bst->right);
        free (bst);
    }
}
