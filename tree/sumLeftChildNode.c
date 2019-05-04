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

void getSum(struct tree *root,int* sum){
    if(root==NULL)
        return;
    if(root->left && root->left->left==NULL && root->left->right==NULL){
        *sum+=root->left->data;
    }

    getSum(root->left,sum);
    getSum(root->right,sum);
    
}

int nodeSum(struct tree *t){
    int sum=0;
    getSum(t,&sum);
    // printf("%dsum",sum);
    return sum;
}


int main(){
    struct tree *root=createNode(9);
    root->left=createNode(8);
    root->right=createNode(6);
    root->left->left=createNode(5);
    root->left->right=createNode(2);
    root->right->left=createNode(1);
    // printf("\nSum = %d\n",getSum(root));
    printf("\nLeft child node Sum = %d\n",nodeSum(root));
    return 0;
}


