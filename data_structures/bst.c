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
void bst_traverse(Node* bst);
void bst_delete(Node* bst);
void bst_print(Node* bst);

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

void bst_remove(Node* bst, int value) {
    if (bst) {
        if (bst->value == value) {
            
        } else if (bst->value > value) {
            bst_remove(bst->left, value);
        } else {
            bst_remove(bst->right, value);
        }
    }
}

Node* bst_find(Node* bst, int value) {
    if (!bst) {
        return NULL;
    } else {
        if (bst->value == value) {
            
        }
    }
}
