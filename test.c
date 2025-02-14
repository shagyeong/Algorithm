//1112: 진법 변환
//알고리즘 분류: 수학, 구현, 정수론
#include<stdio.h>
int main(void){
    int n, b; scanf("%d %d", &n, &b);
    int w;   //가중치
    int ans = 0;
    int buf = n;
    
    if(n < 0){
        n *= -1;
    }

    w = 1;
    while(buf != 0){
        ans += w * (buf % b);
        buf /= b;
        w *= 10;
    }

    if(n < 0){
        printf("%d\n", -ans);
    }
    else{
        printf("%d\n", ans);
    }   
}
