#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Node* bst = node_init(5);
    bst_insert(bst, 1);
    bst_insert(bst, 2);
    bst_insert(bst, 3);
    bst_insert(bst, 4);
    bst_insert(bst, 6);
    bst_insert(bst, 7);
    bst_insert(bst, 8);
    bst_insert(bst, 9);
    bst_inorder(bst);
    bst_remove(bst, 5);
    bst_remove(bst, 9);
    bst_remove(bst, 1);
    bst_inorder(bst);
}

Node* node_init(int value) {
    Node* res = malloc(sizeof(Node));
    res->value = value;
    res->left = NULL;
    res->right = NULL;
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
    if (bst) {
        bst_inorder(bst->left);
        printf("%d \n", bst->value);
        bst_inorder(bst->right);
    } else {
        printf("[NULL] \n");
    }
}

Node* bst_remove(Node* bst, int value) {
    if (!bst) {
        return bst;
    } else if (bst->value > value) {
        bst->left = bst_remove(bst->left, value);
    } else if (bst->value < value) {
        bst->right = bst_remove(bst->right, value);
    } else {
        if (!bst->left) {
            Node* temp = bst->right;
            free(bst);
            return temp;
        } else if (!bst->right) {
            Node* temp = bst->left;
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
