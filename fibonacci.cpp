#include <stdio.h>

int d[100]; // 결과를 담을 수 있는 배열(전역변수로 선언했기 때문에 0으로 초기화) 

// 다이나믹 프로그래밍
int dp(int x) {
    // 피노나치 수열은 맨 처음 2개의 값이 1이기 때문에 초기값 명시
    if(x==1) return 1; 
    if(x==2) return 1;

    // Memoization 
    if(d[x]!=0) return d[x]; // 이미 구한 값이라면 구한 값 자체를 반환 

    return d[x] = dp(x-1) + dp(x-2); // 처음 구한 값이라면 배열에 저장
}

int main(void) {
    printf("%d\n", dp(30));
}