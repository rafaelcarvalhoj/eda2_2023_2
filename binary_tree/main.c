#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}node;

node *search(node *root, int key){
    if(root == NULL || root->data == key) return root;

    if(key < root->data) return search(root->left, key);

    return search(root->right, key);
}

int insert_itr(node *root, int key){
    node *new_node = malloc(sizeof(node));
    new_node->data = key;
    new_node->left = new_node->right = NULL;
    if(root == NULL){
        root = new_node;
        return 0;
    }
    while(1){
        if(key < root->data){
            if(root->left == NULL){
                root->left = new_node;
                break;
            }
            root = root->left;
        }
        if(root->right == NULL){
            root->right = new_node;
            break;
        }
        root = root->right;
    }
    return 0;
}

node *insert(node *root, int key){
    if(root == NULL){
        node *new_node = malloc(sizeof(node));
        new_node->data = key;
        new_node->left = new_node->right = NULL;
        return new_node;
    }

    if(key < root->data)
        root->left = insert(root->left, key);
    
    root->right = insert(root->right, key);

}

node *remove(node *root, int key){
    if(key < root->data){
        root->left = remove(root->left, key);
    }
    else if(key > root->data){
        root->right = remove(root->right, key);
    }
    //key == root->data
    else if(root->left == NULL){
        node *tmp = root->right;
        free(root);
        return tmp;
    }
    else if(root->right == NULL){
        node *tmp = root->left;
        free(root);
        return tmp;
    }

    node *fmin = root;
    node *min = root->right;

    while(min->left != NULL){
         fmin = min;
         min = min->left;
    }
    if(min->right != NULL)
        fmin->left = min->right;
    min->left = root->left;
    if(fmin->right != min)
        min->right = root->right;
    min->right = NULL;
    free(root);
    return min;
}

int main(){
    node *root = malloc(sizeof(node));
}