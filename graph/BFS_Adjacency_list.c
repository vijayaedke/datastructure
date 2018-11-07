#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct graph{
    struct node *head;
    struct graph *array;
    int vertices;
};

struct queue{
    int *array;
    unsigned capacity;
    int front,rear;
};


struct queue* init(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->array=(int *)malloc(sizeof(int)*q->capacity);
    q->front=q->rear=-1;
    return q;
}

void enQueue(int n , struct queue *q){
    if(q->rear==(q->capacity-1)){
        // printf("\nQueue is full\n");
        exit(1);
    }
    
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->rear++;
        q->array[q->rear]=n;
    }
    else{
        q->rear++;
        q->array[q->rear]=n;
    }
}

int deQueue(struct queue *q){
    int n;
    if(q->front==-1){
        // printf("\nQueue is empty\n");
        exit(1);
    }
    
    if(q->front==q->rear){
        n = q->array[q->front];
        q->front=q->rear=-1;
        return n;
    }
    else{
        n = q->array[q->front];
        q->front++;
        return n;
    }
}


struct node *createNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct graph* createGraph(int vert){
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices=vert;
    g->array=(struct graph *)malloc(sizeof(struct graph)*g->vertices);
    for(int i=0;i<vert;i++)
        g->array[i].head=NULL;
    return g;
}

void addEdge(struct graph *g,int src,int dest){
    struct node *temp=createNode(src);
    temp->next=g->array[dest].head;
    g->array[dest].head=temp;
    
    temp=createNode(dest);
    temp->next=g->array[src].head;
    g->array[src].head=temp;
    
}

void printGraph(struct graph *g){
    for(int i=0;i<g->vertices;i++){
        struct node *traverse = g->array[i].head;
        printf("\nNodes Adjacent to %d \t",i);
        while(traverse){
            printf("%d\t",traverse->data);
            traverse=traverse->next;
        }
    }//for
}//printGraph

int isEmpty(struct queue *q){
    return q->rear==-1;
}

void BFS(struct graph *g,int start){
    struct queue *q = init(g->vertices);

    int visited[g->vertices];
    for(int i=0;i<g->vertices;i++){
        visited[i]=0;
    }//for
    
    visited[start]=1;
    enQueue(start,q);
    printf("\nVisited = %d\n",start);
    
    while(!isEmpty(q)){
        int n = deQueue(q);
        for(struct node *p=g->array[n].head;p!=NULL;p=p->next){
            if(visited[p->data]==0){
                  visited[p->data]=1;
                  enQueue(p->data,q);
                  printf("\nVisited = %d\n",p->data);
            }
        }//for
      
    }//while
    
}//BFS

int main(){
    int V = 4; 
    struct graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 2, 0); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 3); 
  
    // print the adjacency list representation of the above graph 
    printGraph(graph); 
    BFS(graph,2);
    
    
    return 0;
}