#include<stdio.h>
#include<stdlib.h>
struct tree{
  int data;
  struct tree *left,*right;
};


struct tree* createNode(int data){
    struct tree *node=(struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}//createnode

int getMin(struct tree *root,int num,int min){

   //check for the base condition and return the current min value
   if(root==NULL)
        return min;
    
   //check for the min number such that min<=num && min<=root->data
   //this condition checks for root->data == num
   if(root->data <= num && min<=root->data)
        min=root->data;

   //if root->data greater than num , then search the min<=num in left subtree recursively
   if(root->data >= num)
        min=getMin(root->left,num,min);
   else //search in right subtree recursively
        min=getMin(root->right,num,min);
    
   //return the current min value
   return min;
    
}//getMin

int main(){

    // creating following BST 
    /* 
                  5 
               /   \  
             2     12 
           /  \    /  \  
          1   3   9   21 
                     /   \   
                    19   25  */
    struct tree *root=createNode(5);
    root->left=createNode(2);
    root->right=createNode(12);
    
    root->left->left=createNode(1);
    root->left->right=createNode(3);
    
    root->right->left=createNode(9);
    root->right->right=createNode(21);
    
    root->right->right->left=createNode(19);
    root->right->right->right=createNode(25);
    
    int min=-1,*prev=0,num=4;
    printf("\n%d",getMin(root,num,min));
    
    // if(root->data > num)
    //     printf("\n%d",getMin(root->left,num,min));
    // else
    //     printf("\n%d",getMin(root->right,num,min));
    
    
	return 0;
}



/*
input : for num = 4
output : 3

input : for num =24
output : 21

input : for num =-9
output : -1

*/
