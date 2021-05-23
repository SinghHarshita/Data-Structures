// Implementation of Binary Tree

#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree
{
    int data;
    struct BinarySearchTree *left, *right;
}tree;

void insert(tree **root,int val);
void deleteLeafNode(tree **root, int val);
tree *search(tree **root, int val);
void preOrderTraversal(tree *root);
void inOrderTraversal(tree *root);
void postOrderTraversal(tree *root);

void main()
{
    tree *root=NULL;
    int choice, n, r;

    do
    {
        printf("\nMenu:- ");
        printf("\n1. Insert ");
        printf("\n2. Delete ");
        printf("\n3. Search ");
        printf("\n4. Pre-order traversal ");
        printf("\n5. Post-order traversal ");
        printf("\n6. In-order traversal ");
        printf("\n0. Exit ");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter value: ");
                    scanf("%d",&n);
                    insert(&root,n);
                    break;
            case 2: printf("\nEnter value: ");
                    scanf("%d",&n);
                    deleteLeafNode(&root,n);
                    break;
            case 3: printf("\nEnter the value: ");
                    scanf("%d",&n);
                    search(&root,n);
                    break;
            case 4: preOrderTraversal(root);
                    break;
            case 5: postOrderTraversal(root);
                    break;
            case 6: inOrderTraversal(root);
                    break;
            case 0: break;
            default: printf("\nINVALID CHOICE! ");
        }
    }
    while(choice!=0);
}

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

tree *search(tree **root, int val)
{
    tree *temp = *root;

    if(temp==NULL)
    {
        printf("\nEmpty Tree! ");
        return NULL;
    }

    while(temp->data!=val)
    {
        if(val<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
        if(temp==NULL)
        {
            printf("\nElement Not Found! ");
            return NULL;
        }
    }
    printf("%d was found",temp->data);
    return temp;
}

void deleteLeafNode(tree **root, int val)
{
    tree *temp = *root, *parent = NULL, *ptr;

    if(temp==NULL)
    {
        printf("\nEmpty Tree ");
        return;
    }

    while(temp->data!=val)
    {
        parent = temp;
        if(val<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
        if(temp==NULL)
        {
            printf("\nElement Not Found ");
            return;
        }
    }

    if(temp->left==NULL&&temp->right==NULL)
    {
        if(parent->right==temp)
            parent->right=NULL;
        else
            parent->left=NULL;
        free(temp);
        return;
    }
    else if(temp->left!=NULL && temp->right==NULL)
    {
        if(parent->right==temp){
            parent->right=temp->left;
        }
        else
            parent->left=temp->left;
        free(temp);
        return;
    }
    else if(temp->left==NULL && temp->right!=NULL)
    {
        if(parent->right==temp)
            parent->right=temp->right;
        else
            parent->left=temp->right;
        free(temp);
        return;
    }
    else
    {
        ptr = temp->right;
        while(ptr->left!=NULL)
        {
            parent = ptr;
            ptr=ptr->left;
        }
        if(ptr->right!=NULL)
        {
            if(parent->right==ptr)
                parent->right=ptr->right;
            else
                parent->left=ptr->right;
        }
        else
        {
            parent->left = NULL;
        }
        temp->data = ptr->data;
        free(ptr);
        return;
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
