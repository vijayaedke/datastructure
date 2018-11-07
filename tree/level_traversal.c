#include<stdio.h>
#include<stdlib.h>

struct tree{
  struct tree *left,*right;
  int data;
};

struct queue{
    struct tree* *array;
    unsigned capacity;
    int front,rear;
};


struct queue* init(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->array=(struct tree **)malloc(sizeof(struct tree)*q->capacity);
    q->front=q->rear=-1;
    return q;
}

struct tree *createNode(int data){
    struct tree *t = (struct tree *)malloc(sizeof(struct tree));
    t->data = data;
    t->left=t->right=NULL;
    return t;
}

void enQueue(struct tree *node , struct queue *q){
    if(q->rear==(q->capacity-1)){
        // printf("\nQueue is full\n");
        exit(1);
    }
    
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->rear++;
        q->array[q->rear]=node;
    }
    else{
        q->rear++;
        q->array[q->rear]=node;
    }
}

struct tree *deQueue(struct queue *q){
    struct tree *node;
    if(q->front==-1){
        // printf("\nQueue is empty\n");
        exit(1);
    }
    
    if(q->front==q->rear){
        node = q->array[q->front];
        q->front=q->rear=-1;
        return node;
    }
    else{
        node = q->array[q->front];
        q->front++;
        return node;
    }
}

void levelTraversal(struct tree *root){
    struct queue *q = init(100);
    struct tree *temp=root;
    
    while(temp!=NULL){
        printf("%d\n",temp->data);
        
        if(temp->left)
            enQueue(temp->left,q);
        if(temp->right)
            enQueue(temp->right,q);
            
        temp=deQueue(q);
    }//while
    
    
}//levelTraversal

int main(){
    struct tree *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->right = createNode(40);
    root->right->right = createNode(50);
    
    levelTraversal(root);
    
    return 0;
    
}


