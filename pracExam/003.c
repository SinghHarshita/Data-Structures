#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *right, *left;
}node;

node *newNode(int key){
    node *n = (node *)malloc(sizeof(node));
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

void insert(node **root, int key){
    node *temp = *root;
    if(*root == NULL){
        *root = newNode(key);
        return;
    }

    if(key<temp->data){
        insert(&temp->left,key);
    }
    else{
        insert(&temp->right,key);
    }
}

void preorderTraversal(node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(node *root){
    if(root!=NULL){

       postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void inorderTraversal(node *root){
    if(root!=NULL){

        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);

    }
}

void deleteNode(node **root,int val){
    node *temp = *root, *parent = NULL, *ptr;
    if(temp == NULL){
        printf("\nEmpty Tree");
        return;
    }

    while(temp->data!=val && temp!=NULL){
        parent = temp;

        if(val<temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == NULL){
        printf("\nNode not found!");
        return;
    }

    if(temp->left == NULL && temp->right == NULL){
        if(parent->right == temp){
            parent->right = NULL;
        }
        else{
            parent->left = NULL;
        }
        free(temp);
        return;
    }

    else if(temp->left==NULL && temp->right != NULL){
        if(parent->right == temp){
            parent->right = temp->right;
        }
        else{
            parent->left = temp->right;
        }
        free(temp);
        return;
    }

    else if(temp->left != NULL && temp->right == NULL){
        if(parent->right == temp){
            parent->right = temp->left;
        }
        else{
            parent->left = temp->left;
        }
        free(temp);
        return;
    }

    else{
        ptr = temp->right;

        while(ptr->left != NULL){
            parent = ptr;
            ptr = ptr->left;
        }

        if(ptr->right != NULL){
            parent->left = ptr->right;
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

node *search(node **root, int key){
    node *temp = *root;

    while(temp->data != key && temp != NULL){
        if(key<temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return temp;
}

int min(node **root){
    node *temp = *root;
    if((*root)->left != NULL){
        min(&temp->left);
    }
    else{
        return (*root)->data;
    }

}

int max(node **root){
    node *temp = *root;
    if((*root)->right!= NULL){
        min(&temp->right);
    }
    else{
      return (*root)->data;
    }
}

int height(node **root){
    int heightLeft ;
    int heightRight ;
    if((*root)==NULL)
        return 0;

        heightLeft = height(&(*root)->left);

        heightRight = height(&(*root)->right);
    if(heightLeft>heightRight)
        return (heightLeft+1);
    else
        return (heightRight+1);
}

int totalNodes(node **root){
    if((*root)==NULL)
        return 0;
    else
        return (totalNodes(&(*root)->left)+totalNodes(&(*root)->right)+1);
}

int totalInternalNodes(node **root){
    if((*root)==NULL || ((*root)->left == NULL && (*root)->right == NULL))
        return 0;
    else
        return (totalInternalNodes(&(*root)->left)+totalInternalNodes(&(*root)->right)+1);
}

int totalExternalNodes(node **root){
    if((*root)==NULL)
        return 0;
    else if((*root)->left == NULL && (*root)->right == NULL)
        return 1;
    else
        return (totalExternalNodes(&(*root)->left)+totalExternalNodes(&(*root)->right));
}

void main(){
    node *root = NULL, *ptr;
    int c,key;

    do{

        printf("\nMENU: \n1. Add a number \n2. Pre-order Traversal \n3.Post-order Traversal \n4. In-order Traversal \n5.Delete \n6.Search \n7.Min \n8.Max \n9.Height \n10. Total Nodes \n11. Total Internal Nodes \n12. Total External Nodes \n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);

        switch(c){
            case 0: break;
            case 1: printf("\nEnter the number to be inserted: ");
                    scanf("%d",&key);
                    insert(&root,key);
                    break;
            case 2: preorderTraversal(root);
                    break;
            case 3: postorderTraversal(root);
                    break;
            case 4: inorderTraversal(root);
                    break;
            case 5: printf("\nEnter the number to be deleted: ");
                    scanf("%d",&key);
                    deleteNode(&root,key);
                    break;
            case 6: printf("\nEnter the number to be searched: ");
                    scanf("%d",&key);
                    ptr = search(&root,key);
                    if(ptr!=NULL){
                        printf("\nElement found! ");
                    }
                    else{
                        printf("\nElement not found! ");
                    }
                    break;
            case 7: printf("\nMIN = %d",min(&root)); break;
            case 8: printf("\nMAX = %d",max(&root)); break;
            case 9: printf("\nHeight = %d",height(&root)); break;
            case 10: printf("\nTotal Nodes = %d",totalNodes(&root)); break;
            case 11: printf("\nTotal Internal Nodes = %d",totalInternalNodes(&root)); break;
            case 12: printf("\nTotal External Nodes = %d",totalExternalNodes(&root)); break;
            default: printf("\nInvalid Choice! ");
        }
    }while(c!=0);
}
