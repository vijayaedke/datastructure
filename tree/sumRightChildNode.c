/*
Find sum of all right leaves in a given Binary Tree
Given a Binary Tree, find sum of all right leaves in it.
Similar article : Find sum of all left leaves in a given Binary Tree

Example :

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
     \        /  \
      2       6   7

Output :
sum = 2 + 5 + 7 = 14
*/

#include<stdio.h>
#include<stdlib.h>

struct tree{
  struct tree *left,*right;
  int data;
};

int sum=0;
struct tree *createNode(int data){
    struct tree *t = (struct tree *)malloc(sizeof(struct tree));
    t->data = data;
    t->left=t->right=NULL;
    return t;
}

int nodeSum(struct tree *root,int* sum){
     if(root==NULL)
        return 0;
    if(root->right && root->right->left==NULL && root->right->right==NULL){
        // printf("\nCurrent root->left = %d",root->left->data);
        *sum+=root->right->data;
    }

    nodeSum(root->left,sum);
    nodeSum(root->right,sum);
    
    return *sum;
}


int main(){
    struct tree *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->left->left->right=createNode(2);
    
    root->right->right=createNode(8);
    root->right->right->left=createNode(6);
    root->right->right->right=createNode(7);
    
    // printf("\nSum = %d\n",getSum(root));
    int sum=0;
    printf("\nRight child node Sum = %d\n",nodeSum(root,&sum));
    return 0;
}


/*
output :


Right child node Sum = 14

*/
