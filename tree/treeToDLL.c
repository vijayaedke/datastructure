#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct tree{
    int data;
    struct tree *left,*right;
};

struct stack{
    struct tree **node;
    int top;
    unsigned capacity;
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

void enQueue( struct queue *q,struct tree *node){
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


struct stack *createStack(unsigned capacity){
    struct stack *s =(struct stack *)malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->node=(struct tree **)malloc(sizeof(struct tree)*s->capacity);
    s->top=-1;
    return s;
}

void push(struct stack *s, struct tree *root){
    if(s->top==MAX-1)
        return;
    s->node[++s->top]=root;
    // printf("\nPushed = %d\n",(s->node[s->top])->data);
}//push

struct tree *pop(struct stack *s){
    if(s->top==-1)
        return 0;
    
    // printf("\nPop = %d\n",(s->node[s->top])->data);
    return s->node[s->top--];
}

void inorderRecursive(struct tree *root){
    if (root == NULL) 
        return; 
    inorderRecursive(root->left);
    printf("%d\t",root->data);
    inorderRecursive(root->right);
}

int isEmpty(struct stack *s){
    if(s->top==-1)
        return 1;
    return 0;
}

void inorderIterative(struct tree *root){
    /* set current to root of binary tree */
  struct tree *current = root; 
  struct stack *s = createStack(100);  /* Initialize stack s */
  int done = 1; 
  
  while (done) 
  { 
    /* Reach the left most tNode of the current tNode */
    if(current) 
    { 
      /* place pointer to a tree node on the stack before traversing  
        the node's left subtree */
      push(s, current);                                                
      current = current->left;   
    } 
         
    /* backtrack from the empty subtree and visit the tNode  
       at the top of the stack; however, if the stack is empty, 
      you are done */
    else                                                              
    { 
      if (!isEmpty(s)) 
      { 
        current = pop(s); 
        printf("%d ", current->data); 
  
        /* we have visited the node and its left subtree. 
          Now, it's right subtree's turn */
        current = current->right; 
      } 
      else
        done = 0;  
    } 
  } /* end of while */
}

void createDoublyLinkedList(struct tree *root,struct tree *head){
    if(root==NULL)
        return;
    static struct tree *prev=NULL;
    createDoublyLinkedList(root->left,head);
    printf("%d\t",root->data);
    if(prev==NULL){
        head=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    createDoublyLinkedList(root->right,head);
}//createDoublyLinkedList

struct tree *createNode(int data){
    struct tree *node=(struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

struct tree *peek(struct queue *q){
    return q->array[0];
}

void BFSTraversal(struct tree *root){
    struct tree *temp=root,*child=NULL,*prev=NULL;
    struct queue *q=init(100);
    enQueue(q,temp);
    
    struct tree *head=(struct tree *)malloc(sizeof(struct tree));
    head->left=head->right=NULL;
    
    while(q->front!=-1){
        temp=deQueue(q);
        child=createNode(temp->data);
        if(prev==NULL){
            head=child;
        }
        else{
            child->left=prev;
            prev->right=child;
        }
        // printf("%d",temp->data);
        prev=child;
        if(temp->left){
            enQueue(q,temp->left);
        }
        if(temp->right){
            enQueue(q,temp->right);
        }
    }
    
    while(head){
        printf("%d\t",head->data);
        head=head->right;
    }
  
}//BFSTraversal

int main() {
    
    struct tree *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    // inorderRecursive(root);
    // inorderIterative(root);
    // struct tree *head=(struct tree *)malloc(sizeof(struct tree));
    // head->left=head->right=NULL;
    // createDoublyLinkedList(root,head);
    BFSTraversal(root);

    return 0;
}
