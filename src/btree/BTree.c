
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0


typedef struct _BTree {
    int data;
    struct _BTree *left;
    struct _BTree *right;
} BTree;

BTree *getNode(int data) {
    BTree *root = (BTree *) malloc(sizeof(BTree));
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void insert_node(BTree *root, int data) {
    BTree *newNode = getNode(data);

    while (root) {
        if (data > root->data) {
            if (!root->right){
                root->right = newNode;
                return;
            } else
                root = root->right;
        } else {
            if (!root->left) {
                root->left = newNode;
                return;
            } else
                root = root->left;
        }
    }
}


int is_BST_R(BTree *root, BTree *left, BTree *right){

    if (!root)
        return true;
    if (left && root->data < left->data)
        return false;
    if (right && root->data >= right->data)
        return false;
    return is_BST_R(root->left , left, root) &&
        is_BST_R(root->right, root, right);
}

int is_BST(BTree *root) {
    if (!root)
        return true;
    else
        return is_BST_R(root, NULL, NULL);
}


// In Order Traversal
void in_orderR(BTree *root) {
    if (!root)
        return;
    in_orderR(root->left);
    printf("%d --> ", root->data);
    in_orderR(root->right);
}

void in_order(BTree *root) {
    printf("\n In order Tree Traversal: ");
    in_orderR(root);
    printf(" [ X ] \n");
}

void pre_order_R(BTree *root) {
    if (!root)
        return;
    printf("%d --> ", root->data);
    in_orderR(root->left);
    in_orderR(root->right);
}

void pre_order(BTree *root) {
    printf("\n Pre Order Tree Traversal : ");
    pre_order_R(root);
    printf(" [ X ] \n");
}


BTree *build_tree(int arr[], int len) {
    if (len <= 0)
        return NULL;

    BTree *root = getNode(arr[0]);

    for (int i = 1 ; i < len; i++) {
        insert_node(root, arr[i]);
    }
    return root;
}

void print_arr(int data[], int len) {
    printf("Array : ");
    for (int i = 0 ; i < len; i++) {
        printf(" %d --> ", data[i]);
    }
    printf(" [x] \n");
}


void make_mirror(BTree *root) {
    if (!root)
        return;

    BTree *temp = root->right;

    root->right = root->left;
    root->left = temp;

    make_mirror(root->left);
    make_mirror(root->right);
}

int is_mirror(BTree *tree1, BTree *tree2) {
    if (!tree1 && !tree2)
        return true;
    else if (!tree1 || !tree2)
        return false;
    else if (tree1->data != tree2->data)
        return false;
    else
        return is_mirror(tree1->left , tree2->right) &&
            is_mirror(tree1->right, tree2->left);
}


void chiral() {
    int data[] = {1,23,6,9,32,3};
    int len = sizeof (data) / sizeof (data[0]);

    BTree *ltree = build_tree(data, len);
    BTree *rtree = build_tree(data, len);

    BTree *root = getNode(15);

    root->left = ltree;
    root->right = rtree;
    make_mirror(root->right);

    printf ("\n%s", is_mirror(root->left, root->right) ? "IS CHIRAL": "NOT CHIRAL");
}

int main (int argc , char *argv[]) {
    int data[] = {1,23,6,9,32,3,45,67, 1, 23, 6};
    int len = sizeof (data) / sizeof (data[0]);

    print_arr(data, len);

    BTree *root = build_tree(data, len);

    // Check Traversals
    in_order(root);
    pre_order(root);

    // Check if Binary Tree
    printf("\n%s", is_BST(root) ? "Is BST" : "Not BST");

    // Check if mirror
    chiral();



    return 0;
}

