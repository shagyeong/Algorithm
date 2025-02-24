//1238: 파티(그래프 이론, 최단 경로, 데이크스트라)
#include<stdio.h>
#include<stdlib.h>

#define NODEMAX 1001
#define INF 32767   //short 최대값
#define NOTSURE -1
#define ALLDONE 1

struct node{
    short value;
    short weight;
    struct node* next;
};
struct graph{
    struct node* adjs[NODEMAX];
    short distance[NODEMAX];
    char visited[NODEMAX];      //노드 마크
};
void Graph(struct graph* G, short n);
void visitinit(struct graph* G, short n);
void distanceinit(struct graph* G, short n);
void insert(struct graph* G, short u, short v, short w);
void dijkstra(struct graph* G, short s, short n);

int main(void){
    short i, j, k;
    short u, v, w;
    short n, m, x; scanf("%hd %hd %hd", &n, &m, &x);

    short ans[n + 1]; for(i = 1; i <= n; i++){ans[i] = 0;}
        
    struct graph* G1 = (struct graph*)malloc(sizeof(struct graph));
    struct graph* G2 = (struct graph*)malloc(sizeof(struct graph));
    Graph(G1, n);
    Graph(G2, n);
    
    for(i = 0; i < m; i++){
        scanf("%hd %hd %hd", &u, &v, &w);
        insert(G1, u, v, w);
        insert(G2, v, u, w);
    }
    dijkstra(G1, x, n); for(i = 1; i <= n; i++){ans[i] += G1->distance[i];}
    dijkstra(G2, x, n); for(i = 1; i <= n; i++){ans[i] += G2->distance[i];}
    //정답 출력
    short max = ans[1];
    i = 1;
    while(i <= n){max = (ans[i] > max)?ans[i]:max; i++;}
    printf("%hd", max);
}
void Graph(struct graph* G, short n){
    for(short i = 1; i <= n; i++){
        //노드 세팅
        struct node* newnode =(struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->weight = 0;
        newnode->next = NULL;
        G->adjs[i] = newnode;
        //최단 경로용 배열 초기화
        G->distance[i] = (short)INF;
        G->visited[i] = NOTSURE;
    }
}
void distanceinit(struct graph* G, short n){
    for(short i = 1; i <= n; i++){G->distance[i] = (short)INF;}   
}
void visitinit(struct graph* G, short n){
    for(short i = 1; i <= n; i++){G->visited[i] = NOTSURE;}   
}
void insert(struct graph* G, short u, short v, short w){
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    struct node* U = (struct node*)malloc(sizeof(struct node));
    struct node* V = (struct node*)malloc(sizeof(struct node));
    U->value = u; U->weight = w; U->next = NULL;
    V->value = v; V->weight = w; V->next = NULL;
    
    //가중치 오름차순을 유지하며 인접리스트에 삽입
    buf = G->adjs[u];
    while((buf->next != NULL) && (w > buf->next->weight)){buf = buf->next;}
    V->next = buf->next; buf->next = V;
    //무향 그래프에서 활성화
    //buf = G->adjs[v];
    //while((buf->next != NULL) && (w > buf->next->weight)){buf = buf->next;}
    //U->next = buf->next; buf->next = U;
}
void dijkstra(struct graph* G, short s, short n){
    short ibuf;
    short wbuf;
    G->distance[s] = 0;
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    
    for(short i = 1; i <= n; i++){
        ibuf = 1;
        wbuf = 32767;
        for(short j = 1; j <= n; j++){
            if(G->distance[j] < wbuf && G->visited[j] == NOTSURE){
                wbuf = G->distance[j];
                ibuf = j;
            }
        }

        buf = G->adjs[ibuf]->next;
        while(buf != NULL){
            if((wbuf + buf->weight > 0) && (wbuf + buf->weight < G->distance[buf->value])){
                G->distance[buf->value] = wbuf + buf->weight;
            }
            buf = buf->next;
        }
        G->visited[ibuf] = ALLDONE;
    }
}

// void printgraph(struct graph* G, short n);
// void printgraph(struct graph* G, short n){
//     struct node* buf = (struct node*)malloc(sizeof(struct node));
//     for(short i = 1; i <= n; i++){
//         buf = G->adjs[i];
//         printf("node %hd's adjs: \n", buf->value);
//         buf = buf->next;
//         while(buf != NULL){
//             printf("node %hd: weight %hd\n", buf->value, buf->weight);
//             buf = buf->next;
//         }printf("\n");
//     }
// }
