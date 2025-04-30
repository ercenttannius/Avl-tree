#include <stdio.h>
#include <stdlib.h>

// ARKAN dari ambil library, struct node, createNode, getHeight, getBalance

struct Node{
    int key;
    Node *left;
    Node *right;
    int height;
};

Node *createNode(int key){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int getHeight(Node *node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int getBalance(Node *node){
    if(node == NULL){
        return 0;
    }

    return getHeight(node->left) - getHeight((node->right));
}

// Ercent dari max, rightRotate, leftRotate

int max(int a, int b){ //buat ngambil nilai pohon tertinggi nya 
    if(a > b){
        return a;
    }
    else{ //kalauu b lebih besar
        return b;
    }
}

Node *rightRotate(Node *node){
    Node *a = node->left;
    Node *b = a->right;

    //rotatenya
    a->right = node;
    node->left = b;

    //update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    a->height = 1 + max(getHeight(node->left), getHeight(node->right));

    return node;
}

Node *leftRotate(Node *node){
    Node *a = node->right;
    Node *b = a->left;

    //rotatenya
    a->left = node;
    node->right = b;

    //update tinggi
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    a->height = 1 + max(getHeight(node->left), getHeight(node->right));

    return node;
}

// Jason insertNode, inOrder, Main

Node *insertNode(Node *node, int key){
    Node *temp = createNode(key);
    
    if(node == NULL){
        return temp;
    }

    else if(key < node->key){
        node->left = insertNode(node->left, key);
    }

    else if(key > node->key){
        node->right = insertNode(node->right, key);
    }

    //update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Balance Check
    int balance = getBalance(node);

    // if not Balance
    //left left
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }

    // left right
    else if(balance > 1 && key > node ->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //right right
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }

    // left right
    else if(balance < -1 && key < node ->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node *node){
    if(node != NULL){
        inOrder(node->left);
        printf("%d -> ", node->key);
        inOrder(node->right);
    }
}

int main(){
    Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 17);

    inOrder(root);
    return 0;
}
