//2164: 카드 2(자료 구조, 큐)
#include<stdio.h>
int main(void){
    int n; scanf("%d", &n);
    n = (n % 2 == 0)?n:2;
    printf("%d", n);
}