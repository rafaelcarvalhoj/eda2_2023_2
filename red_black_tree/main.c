#include <stdlib.h>

enum color { RED, BLACK };

typedef struct node{
    int key;
    enum color color;
    struct node *left, *right;
} node;

typedef node* p_node;

int isRed(p_node x){
    if(x==NULL) return 0;
    return x->color == RED;
}

int isBlack(p_node x){
    if(x==NULL) return 1;
    return x->color == BLACK;
}

p_node rotate_left(p_node root){
    p_node x = root->right;
    root->right = x->left;
    x->left = root;
    x->color = root->color;
    root->color = RED;
    return x;
}

p_node rotate_right(p_node root){
    p_node a = root->left;
    root->left = a->right;
    a->right = root;
    a->color = root->color;
    root->color = RED;
    return a;
}

void up_red(p_node root){
    root->color = RED;
    root->left->color = BLACK;
    root->right->color = BLACK;
}


p_node insert_rec(p_node root, int key){
    if(root==NULL){
        p_node new = malloc(sizeof(node));
        new->key = key;
        new->left = new->right = NULL;
        new->color = RED;
        return new;
    }
    if(key < root->key)
        root->left = insert_rec(root->left, key);
    root->right = insert_rec(root->right, key);

    //set the tree
    if(isRed(root->right) && isBlack(root->left))
        root = rotate_left(root);
    if(isRed(root->left) && isRed(root->left->left))
        root = rotate_right(root);
    if(isRed(root->left) && isRed(root->right))
        up_red(root);

    return root;
}

p_node insert(p_node root, int key){
    root = insert_rec(root, key);
    root->color = BLACK;
    return root;
}