#include<stdio.h>
#include<stdlib.h>

struct bin {
    int val;
    struct bin *left;
    struct bin *right;
};

typedef struct bin bin;
bin *head=NULL;

bin *newNode(int num) {
    bin *new = malloc(sizeof(bin));
    new->val=num;
    new->left=NULL;
    new->right=NULL;

    return new;
}

bin *preorder(bin *root) {
    if(root==NULL)
        return NULL;
    printf("%d\n",root->val);
    preorder(root->left);
    preorder(root->right);
}

bin *inorder(bin *root) {
    if(root==NULL)
        return NULL;

    inorder(root->left);
    printf("%d\n",root->val);
    inorder(root->right);
}

bin *postorder(bin *root) {
    if(root==NULL)
        return NULL;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->val);
}

int main() {
    bin *rootNode = newNode(2);
    rootNode->left = newNode(5);
    rootNode->right = newNode(6);

    rootNode->left->left = newNode(10);
    rootNode->left->right = newNode(1);
    rootNode->right->left = newNode(4);
    rootNode->right->right = newNode(7);

    printf("Predorder\n");
    preorder(rootNode);

    printf("Inorder\n");
    inorder(rootNode);

    printf("Postorder\n");
    postorder(rootNode);

    return 0;
}