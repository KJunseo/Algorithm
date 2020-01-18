#include <stdio.h>
#include <iostream>
using namespace std;

int number = 10;
int arr[] = {1,6,9,8,2,4,10,3,7,5}; // 정렬할 배열

void quickSort(int *data, int start, int end){ // start는 집합의 시작 부분, end는 끝 부분
    // 원소가 한 개인 경우
    if(start >= end){
        return;
    }

    int key = start; // pivot 값 설정(첫 번째 원소)
    int i = start + 1; // pivot을 제외하고, 왼쪽부터 오른쪽으로 탐색하기 위한 index
    int j = end; // 맨 오른쪽에서 왼쪽으로 탐색하기 위한 index

    int temp; // 두 수를 교환하기 위한 임시 변수

    // 엇갈릴 때 까지 반복 
    while(i <= j){
        // pivot 값 보다 작다면, 오른쪽으로 이동(왼쪽에서 오른쪽으로 탐색하는 경우)
        // pivot 값 보다 큰 값을 만날 때 까지 반복
        while(i <= end && data[i] <= data[key]){
            i++;
        }
        // pivot 값 보다 크다면, 왼쪽으로 이동(오른쪽에서 왼쪽으로 탐색하는 경우)
        // pivot 값 보다 작은 값을 만날 때 까지 반복
        // 범위를 넘어가지 않도록 j는 최대 start까지만
        while(j > start && data[j] >= data[key]){
            j--;
        }
        // 엇갈린 상태면 키 값과 교체
        if(i>j){
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else{ // 엇갈리지 않은 상태라면, 둘의 값을 바꿔줌 
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    // 엇갈려서 while문을 빠져나왔으면, pivot 값을 기준으로 왼쪽 집합, 오른쪽 집합 각각 quick sort
    quickSort(data, start, j-1);
    quickSort(data, j+1, end);

}
int main(void){

    quickSort(arr, 0, number-1);
    for(int i=0;i<number;i++){
        cout<<arr[i]<<endl; 
    }
    return 0;
}

