#include <stdio.h>
#include <stdlib.h>
#define capacity 4

struct list{
  int data;
  struct list *next;
};


struct graph{
  struct list *head;
};

struct list *createNode(int data){
    struct list *newnode = (struct list *)malloc(sizeof(struct list));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addEdge(struct graph **g, int src, int dest){
    struct list *newnode = createNode(dest);
    struct list *p = (g[src]->head);
    if(!p){
        g[src]->head = newnode;
    }//if
    else{
        while(p->next){
            p=p->next;
        }//while
        p->next = newnode;
    }//else
}//addEdge

void printGraph(struct graph **g, int size){
    
    for(int i=0;i<size;i++){
        struct list *p = g[i]->head;
        if(p){
            printf("\n%d-->", i);
            while(p){
                printf("%d->", p->data);
                p=p->next;
            }//while    
        }//if
    }//for
}//printGraph

void util(struct graph **g, int *visited, int current){
    if(!g[current])
        return;
    
    struct graph *start = g[current];
    struct list *temp = start->head;
    while(temp){
        if(!visited[temp->data]){
            visited[temp->data]=1;
            printf("%d->", temp->data);
            util(g, visited, temp->data);
        }
        temp = temp->next;
    }//while
}//util

void DFS(struct graph **g, int start_node){
    int visited[capacity] = {0};
    printf("%d->", start_node);
    visited[start_node] = 1;
    util(g, visited, start_node);
}//DFS

int main() {
	//code
	struct graph *g[capacity]={0};
	for(int i=0;i<capacity;i++){
	    g[i] = (struct graph *)malloc(sizeof(struct graph));
	    g[i]->head = NULL;
	}
	
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	
	addEdge(g, 1, 2);
	
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    
    addEdge(g, 3, 3);

    printGraph(g, 4);
    printf("\n==================DFS==================\n");
    DFS(g, 0);
	return 0;
}

/*output
0-->1->2->
1-->2->
2-->0->3->
3-->3->
==================DFS==================
0->1->2->3->

*/
