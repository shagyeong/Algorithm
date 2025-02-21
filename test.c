#include<stdio.h>
#include<string.h>
void mergesort(char s[], unsigned char l, unsigned char r);
void merge(char s[], unsigned char l, unsigned char m, unsigned char r);

//길이가 2n + 1인 문자열에 대해: 같은 문자가 n + 1개 이하여야 함
//길이가 2n인 문자열에대해     : 같은 문자가 n개 이하여야 함
int main(void){
    char s[50]; scanf("%s", s);
    unsigned char len = (unsigned char)strlen(s);
    mergesort(s, 0, len - 1);
    //

}
void mergesort(char s[], unsigned char l, unsigned char r){
    if(l < r){
        unsigned char m = (l + r) / 2;
        mergesort(s, l, m);
        mergesort(s, m + 1, r);
        merge(s, l, m, r);
    }
}
void merge(char s[], unsigned char l, unsigned char m, unsigned char r){
    unsigned char i, j, k;

    unsigned char left = m - l + 1;     char L[left];
    for(i = 0; i < left; i++){L[i] = s[l + i];}
    unsigned char right = r - m;        char R[right];
    for(i = 0; i < right; i++){R[i] = s[m + 1 + i];}

    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i] < R[i]){
            s[k++] = L[i++];
        }
        else{
            s[k++] = R[j++];
        }
    }
    while(i < left){
        s[k++] = L[i++];
    }
    while(j < right){
        s[k++] = R[j++];
    }
}
