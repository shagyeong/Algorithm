#include<stdio.h>
#include<stdlib.h>

#define NODEMAX 5

struct node{
    unsigned short value;
    struct node* next;
};
struct graph{
    struct node* adjs[NODEMAX];
};
void Graph(struct graph* G);
void insert(struct graph* G, unsigned short u, unsigned short v);
void DFS(struct graph* G, unsigned short u);
void printgraph(struct graph* G);

int main(void){
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));
    Graph(G);
    insert(G, 1, 3);
    insert(G, 2, 4);
    insert(G, 3, 4);
    insert(G, 2, 3);
    printgraph(G);
}
void Graph(struct graph* G){
    for(unsigned short i = 0; i < NODEMAX; i++){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->next = NULL;
        G->adjs[i] = newnode;
    }
}
void insert(struct graph* G, unsigned short u, unsigned short v){
    struct node* U = (struct node*)malloc(sizeof(struct node));
    struct node* V = (struct node*)malloc(sizeof(struct node));
    U->value = u; U->next = NULL;
    V->value = v; V->next = NULL;
    
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    buf = G->adjs[u];
    while(buf->next != NULL){buf = buf->next;}
    buf->next = V;
    buf = G->adjs[v];
    while(buf->next != NULL){buf = buf->next;}
    buf->next = U;
}
void DFS(struct graph* G, unsigned short u){
    char visited[NODEMAX];
    for(unsigned short i = 0; i < NODEMAX; i++){visited[i] = 0;}
    //...
}
void printgraph(struct graph* G){
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    for(unsigned short i = 0; i < NODEMAX; i++){
        buf = G->adjs[i];
        printf("node %d: ", buf->value);
        buf = buf->next;
        while(buf != NULL){
            printf("%d ", buf->value);
            buf = buf->next;
        }printf("\n");
    }
}