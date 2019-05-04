/*
Find sum of all left leaves in a given Binary Tree
Given a Binary Tree, find sum of all left leaves in it. For example, sum of all left leaves in below Binary Tree is 5+1=6.
tree

Examples:
Input : Binary tree with x = 2:
        9        
       / \       
      8   6      
     / \ /      
    5  2 1 
    
output : 5+1 = 6
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
    if(root->left && root->left->left==NULL && root->left->right==NULL){
        // printf("\nCurrent root->left = %d",root->left->data);
        *sum+=root->left->data;
    }

    nodeSum(root->left,sum);
    nodeSum(root->right,sum);
    
    return *sum;
}


int main(){
    struct tree *root=createNode(9);
    root->left=createNode(8);
    root->right=createNode(6);
    root->left->left=createNode(5);
    root->left->right=createNode(2);
    root->right->left=createNode(1);
    // printf("\nSum = %d\n",getSum(root));
    int sum=0;
    printf("\nLeft child node Sum = %d\n",nodeSum(root,&sum));
    return 0;
}


/*output:
 
Left child node Sum = 6
*/

