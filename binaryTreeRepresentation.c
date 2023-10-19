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

bin *insert(bin *root,int num) {
    if(root == NULL)
        return newNode(num);
    if(root->val < num)
        root->right = insert(root->right,num);
    else if(root->val > num)
        root->left = insert(root->left,num);
    return root;
}

void insertorder(bin *root)
{
    if(root == NULL)
        return;
    insertorder(root->left);
    printf("%d ",root->val);
    insertorder(root->right);
}

int main() {
    bin *rootNode = NULL;

    rootNode= insert(rootNode,1);
    rootNode = insert(rootNode,7);
    rootNode = insert(rootNode,4);
    rootNode = insert(rootNode,8);
    rootNode = insert(rootNode,1);
    rootNode = insert(rootNode,5);
    rootNode = insert(rootNode,2);
    rootNode = insert(rootNode,9);
    rootNode = insert(rootNode,3);
    insertorder(rootNode);
    return 0;
}