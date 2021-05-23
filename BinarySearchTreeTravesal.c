// // Implementation of Binary Tree Travesal

#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree *left, *right;
}tree;

void insert(tree **root,int data) {
   tree *tempNode = (tree*) malloc(sizeof(tree));
   tree *current = *root;
   tree *parent;

   tempNode->data = data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   if(*root == NULL) {
      *root = tempNode;
   } else {
      parent = NULL;

      while(1) {
         parent = current;

         if(data < parent->data) {
            current = current->left;


         if(current == NULL) {
               parent->left = tempNode;
               return;
            }
         }
         else {
            current = current->right;

            if(current == NULL) {
               parent->right = tempNode;
               return;
            }
         }
      }
   }
}

void preOrderTraversal(tree *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(tree *root)
{
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(tree *root)
{
    if(root!=NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void main()
{
    tree *root = NULL;
    int choice, n;

    do
    {
        printf("\nMENU: ");
        printf("\n1. Insert ");
        printf("\n2. Pre-order Traversal ");
        printf("\n3. Post-order Traversal ");
        printf("\n4. In-order Traversal ");
        printf("\n0. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter the number to be inserted: ");
                    scanf("%d",&n);
                    insert(&root,n);
                    break;
            case 2: preOrderTraversal(root);
                    break;
            case 3: postOrderTraversal(root);
                    break;
            case 4: inOrderTraversal(root);
                    break;
            case 0: break;
            default: printf("\nInvalid Choice! ");
        }
    }
    while(choice!=0);
}
