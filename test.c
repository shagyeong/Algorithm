//1016: 제곱 ㄴㄴ 수
//알고리즘 분류: 수학, 정수론, 소수 판정, 에라토스테네스의 체
#include<stdio.h>
#define MAX 1000000
#define NUM 78498       //1000000까지 소수 개수
void sieve(int min, int max);

int main(void){
    //입력 값 세팅
    int min, max; scanf("%d %d", &min, &max);
    sieve(min, max);
}
void sieve(int min, int max){
    int count = 0;
    int i; int j;
    //natural: 자연수 배열
    int natural[MAX]; for(i = 0; i < MAX; i++){natural[i] = i;}
    natural[0] = 0; natural[1] = 1;
    //prime: 소수 전용 배열
    int prime[NUM];
    int cur = 2;
    int ind;
    while(cur <= MAX - 1){
        ind = cur;
        while(ind + cur <= MAX - 1){
            ind += cur;
            natural[ind] = 0;
        }
        prime[count] =  cur * cur;      //소수 전용 배열에 넣기
        count++; cur++;
        while(natural[cur] == 0){
            cur++;
        }
        
    }

    count = 0;
    for(i = min; i <= max; i++){
        j = 0;
        while(prime[j] <= i && j < NUM){
            if(i % prime[j] == 0){
                count -= 1;
                break;
            }
            else{
                j++;
            }
        }
        count += 1;
    }
    printf("%d", count);
}
