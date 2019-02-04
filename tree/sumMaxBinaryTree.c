/*
Find maximum level sum in Binary Tree
Given a Binary Tree having positive and negative nodes, the task is to find maximum sum level in it.
Examples:
Input :               4
                    /   \
                   2    -5
                  / \    /\
                -1   3 -2  6
Output: 6
Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 0'th level is 6
Hence maximum sum is 6
Input :          1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7  
Output :  17
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct tree {
  int data;
  struct tree *left,*right;
};

struct queue{
    struct tree **array;
    int front,rear;
    unsigned capacity;
};

struct queue* init(unsigned size){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity=size;
    q->array=(struct tree **)malloc(sizeof(struct tree )*q->capacity);
    q->front=q->rear=-1;
    return q;
}//init

struct tree *createNode(int data){
    struct tree *node =(struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}//createNode

void enQueue(struct queue *q,struct tree *node){
    if(q->rear==q->capacity-1)
        return;
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->array[++q->rear]=node;
    }//if
    else{
        q->array[++q->rear]=node;
    }//else
}//enQueue

struct tree* deQueue(struct queue *q){
    if(q->front==-1)
        return NULL;
    struct tree *node;
    if(q->front==q->rear){
        node=q->array[q->front];
        q->front=q->rear=-1;
    }
    else{
        node=q->array[q->front++];
    }
    return node;
}//deQueue

int isEmpty(struct queue *q){
    return q->front==-1;
}//isEmpty

int getMax(int a,int b){
    return a>b?a:b;  
}

int getSize(struct queue *q){
    return (q->rear-q->front)+1;
}

void levelTraversal(struct tree *root){
    struct queue *q= init(7);
    struct tree *temp=root;
    int count=5;
    int max=INT_MIN;
    enQueue(q,temp);
    while(!isEmpty(q)){
        int sum=0;
        count=getSize(q);
        printf("level = %d",count);
        while(count--){
            temp = deQueue(q);
            sum+=temp->data;
            if(temp->left)
                enQueue(q,temp->left);
            if(temp->right)
                enQueue(q,temp->right);
        }//while
            printf("\tsum=%d\n",getMax(sum,max));
    }//while
    
}//levelTraversal

int main() {
    struct tree *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left  = createNode(4); 
    root->left->right = createNode(5); 
    root->right->right = createNode(8); 
    root->right->right->left  = createNode(6); 
    root->right->right->right  = createNode(7); 
    struct queue *q=init(10);

    levelTraversal(root);
    return 0;   
}

/*
output : 
level = 1	sum=1
level = 2	sum=5
level = 3	sum=17
level = 2	sum=13
*/
