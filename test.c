//1240: 노드사이의 거리
//알고리즘 분류: 그래프 이론, 그래프 탐색, 트리, 너비 우선 타색, 깊이 우선 탐색
#include<stdio.h>
struct edge{
    int u;  //노드 1
    int v;  //노드 2
    int w;  //가중치
};
int main(void){
    int n; int m;   //노드 개수 N, 간선 개수 N - 1, 노드 쌍 M개
    int u; int v;   //노드 번호
    int w;          //가중치
    scanf("%d %d", &n, &m);
    struct edge Graph[n - 1];

    for(int i = 0; i < n - 1; i++){
        scanf("%d %d %d", &u, &v, &w);
        Graph[i].u = u;
        Graph[i].v = v;
        Graph[i].w = w;
    }

    for(int i =0; i < n - 1; i++){
        u = Graph[i].u;
        v = Graph[i].v;
        w = Graph[i].w;
        printf("u: %d v: %d, weight: %d\n", u, v, w);
    }
}
