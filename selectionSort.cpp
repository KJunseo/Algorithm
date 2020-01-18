#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int i, j; // 배열의 요소들을 반복적으로 탐색하기 위함
    int min; // 최소 값
    int index; // 가장 작은 값이 존재하는 위치
    int temp; // 서로 다른 두 숫자를 바꿔주기 위해 사용 

    int array[10] = {1,6,9,8,2,4,10,3,7,5}; // 정렬할 배열

    for(int i=0;i<10;i++){
        min = 10000; // 모든 원소들 보다 큰 임의의 수 
        for(j=i;j<10;j++){ 
            // 정렬 되지 않은 나머지 부분에서 가장 작은 값 찾기 
            if(min > array[j]){
                min = array[j];
                index = j;
            }
        }
        // 가장 작은 값이랑 원래 앞에 있던 값이랑 자리 바꾸기 
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
    for(i=0;i<10;i++){
        cout << array[i] << endl;
    }
    return 0;
}
