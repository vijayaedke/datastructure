/*

Sum of all the parent nodes having child node x
Given a binary tree containing n nodes. The problem is to find the sum of all the parent node’s which have a child node with value x.

Examples:

Input : Binary tree with x = 2:
        4        
       / \       
      2   5      
     / \ / \     
    7  2 2  3    
Output : 11

        4        
       / \       
      2   5      
     / \ / \     
    7  2 2  3    

The highlighted nodes (4, 2, 5) above
are the nodes having 2 as a child node.

Algorithm:

sumOfParentOfX(root,sum,x)
    if root == NULL
        return

    if (root->left && root->left->data == x) ||
       (root->right && root->right->data == x)
        sum += root->data
    
    sumOfParentOfX(root->left, sum, x)
    sumOfParentOfX(root->right, sum, x)
    
sumOfParentOfXUtil(root,x)
    Declare sum = 0
    sumOfParentOfX(root, sum, x)
    return sum
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

void getSum(struct tree *root,int* sum,int x){
    if(root==NULL)
        return;
    if( (root->left && root->left->data==x)||(root->right && root->right->data==x) ){
        *sum+=root->data;
    }
        getSum(root->left,sum,x);
        getSum(root->right,sum,x);
}

int nodeSum(struct tree *t,int x){
    int sum=0;
    getSum(t,&sum,x);
    return sum;
}


int main(){
    struct tree *root=createNode(4);
    root->left=createNode(2);
    root->right=createNode(5);
    root->left->left=createNode(7);
    root->left->right=createNode(2);
    root->right->left=createNode(2);
    root->right->right=createNode(3);
    // printf("\nSum = %d\n",getSum(root));
    printf("\nParent node Sum = %d\n",nodeSum(root,2));
    return 0;
}
