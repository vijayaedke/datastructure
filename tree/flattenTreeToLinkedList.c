/*
Given a binary tree, flatten it into a linked list. After flattening, 
the left of each node should point to NULL and right should contain next node in level order.
Input: 
          1
        /   \
       2     5
      / \     \
     3   4     6

Output:
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6


*/
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left,*right;
};


struct stack{
  int top;
  struct TreeNode **array;
  unsigned capacity;
};

struct stack *init(unsigned capacity){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->array=(struct TreeNode **)malloc(sizeof(struct TreeNode)*s->capacity);
    s->top=-1;
    return s;
}//init

int isEmpty(struct stack *s){
    return s->top==-1;
}

int isFull(struct stack *s){
    return s->top==s->capacity-1;
}

void push(struct stack *s,struct TreeNode *t){
    if(isFull(s))
        return;
        
    s->array[++s->top]=t;
}//push

struct TreeNode *pop(struct stack *s){
    if(isEmpty(s))
        return NULL;
    
    return s->array[s->top--];
}//pop

struct TreeNode *createNode(int data){
    struct TreeNode *newnode=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->val=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}//createNode

int countNodes(struct TreeNode *root){
    int count=0;
    if(root==NULL)
        return 0;
    else{
        if(root->left){ 
            count++;
            count+=countNodes(root->left);
        }
        if(root->right){ 
            count++;
            count+=countNodes(root->right);
        }
        return count;
    }//else
}//countNodes

struct TreeNode* flatten(struct TreeNode *root){
   struct stack *s=init(countNodes(root)+1);
   struct TreeNode *temp=root;
   
   while(temp || !isEmpty(s)){
       
       if(temp->right){
           push(s,temp->right);
       }
       
       temp->right=temp->left;
       temp->left=NULL;
       
       if(temp->right==NULL && !isEmpty(s)){
           temp->right=pop(s);
       }//if
       
       temp=temp->right;
   }//while
   
   return root;
}//flatten

void printTree(struct TreeNode *t){
    printf("\n------Linked List------\n");
    while(t){
        printf("%d->",t->val);
        t=t->right;
    }
}

int main() {
    
    struct TreeNode *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(5);
    
    root->left->left=createNode(3);
    root->left->right=createNode(4);
    
    root->right->right=createNode(6);
    
    root=flatten(root);
    printTree(root);
    return 0;
}//main


/*
output :
------Linked List------
1->2->3->4->5->6->
*/
