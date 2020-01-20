#include <stdio.h>
#include <iostream>

using namespace std;

// 주어진 5이하의 자연수 데이터를 오름차순 정렬하는 문제
int main(void) {
    int temp;
    int count[5] = {0}; // 주어진 숫자들이 1, 2, 3, 4, 5 이기 때문에 5칸의 배열을 만들어줌 
    
    // 정렬할 자연수 데이터들 
    int array[30] = {
        1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
        3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
        3, 1, 4, 3, 5, 1, 2, 1, 1, 1
    };

    for(int i=0; i<30; i++){
        count[array[i]-1]++; //각 숫자별 카운트 
    }

    // 각 갯수만큼 출력 
    for(int i=0; i<5; i++){
        if(count[i] != 0){
            for(int j=0; j<count[i]; j++){
                cout << i+1 << ' ';
            }
        }
    }

    return 0;
} 