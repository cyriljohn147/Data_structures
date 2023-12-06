// C program to implement insertion and deletion in BST.
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int key;
  struct Node *left, *right;
};

struct Node* newNode(int item) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct Node* root) {
  if (root != NULL) {
    printf("%d ", root->key);
    inorder(root->left);
    inorder(root->right);
  }
}

struct Node* insert(struct Node* node, int key) {
  if (node == NULL)
    return newNode(key);
  
  if (key < node->key)
    node->left = insert(node->left, key);
  
  else
    node->right = insert(node->right, key);

  return node;
}

struct Node* deleteNode(struct Node* root, int k) {
  if (root == NULL)
    return root;
  
  if (root->key > k) {
    root->left = deleteNode(root->left, k);
    return root;
  }

  else if (root->key < k) {
    root->right = deleteNode(root->right, k);
    return root;
  }

  if (root->left == NULL) {
    struct Node* temp = root->right;
    free(root);
    return temp;
  }

  else if (root->right == NULL) {
    struct Node* temp = root->left;
    free(root);
    return temp;
  }
    //if both children exists
  else {
    struct Node* succParent = root;
    struct Node* succ = root->right;
    while (succ->left != NULL) {
      succParent = succ;
      succ = succ->left;
    }
    
    if (succParent != root)
      succParent->left = succ->right;
    
    else
      succParent->right = succ->right;
    
    root->key = succ->key;
    free(succ);
    return root;
  }
}

int search(struct Node *root,int num) {
  struct Node *temp = root;

  while(temp!=NULL) {
    if(temp->key == num)
      return 1;

    else if(temp->key < num)
      temp = temp->right;

    else if(temp->key > num)
       temp = temp->left;
  }

  return 0;
}

int main() {
  struct Node* root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  
  printf("Original BST: ");
  inorder(root);

  printf("\n\nDelete a Leaf Node: 20\n");
  root = deleteNode(root, 20);

  printf("Modified BST tree after deleting Leaf Node:\n");
  inorder(root);

  printf("\n\nDelete Node with single child: 70\n");
  root = deleteNode(root, 70);

  printf("Modified BST tree after deleting single child Node:\n");
  inorder(root);

  printf("\n\nDelete Node with both child: 50\n");
  root = deleteNode(root, 50);

  printf("Modified BST tree after deleting both child Node:\n");
  inorder(root);

  printf("\nSearch element 60:\n");
  printf((search(root,60))?"Element found!":"Element not present in the list");

  return 0;
}
