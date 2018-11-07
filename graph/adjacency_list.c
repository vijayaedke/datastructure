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
}

int main(){
    int V = 5; 
    struct graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  
    // print the adjacency list representation of the above graph 
    printGraph(graph); 
    
    
    return 0;
}
