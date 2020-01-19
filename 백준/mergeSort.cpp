#include <stdio.h>
#include <iostream>
using namespace std;

int number = 8; // 정렬할 데이터의 수 
int sorted[8]; // 정렬 된 결과를 담을 곳  

void merge (int *data, int start, int middle, int end){ 
    int i = start; // 첫 번째 집합의 탐색 시작 점  
    int j = middle + 1; // 두 번째 집합의 탐색 시작 점 

    int k = start; // 정렬한 결과를 담을 배열의 index 

    // 작은 순서대로 배열에 삽입
    while(i <= middle && j <= end){
        // 첫 번째 배열의 요소가 두 번째 배열의 요소 값 보다 작다면
        if(data[i] <= data[j]){
           sorted[k] = data[i];
           i++;  
        } else {
            sorted[k] = data[j];
            j++;
        }
        k++;
    }
    // 남은 데이터 삽입(i 나 j의 모든 요소가 배열에 들어간 경우 나머지의 요소도 배열에 넣어줘야 함)
    // i 값이 모두 배열에 들어간 경우
    if(i > middle){
        for(int t=j;t<=end;t++){
            sorted[k] = data[t];
            k++;
        }
    } else { // j 값이 모두 배열에 들어간 경우 
        for(int t=i;t<=middle;t++){
            sorted[k] = data[t];
            k++;
        }
    }
    // 정렬된 배열을 삽입
    for(int t=start;t<=end;t++){
        data[t] = sorted[t];
    }

}

void mergeSort(int *data, int start, int end){

    // 크기가 1보다 큰 경우
    if(start < end){
        int middle = (start + end) / 2; // 시작과 끝을 더하여 반으로 나눠줌 
         mergeSort(data, start, middle); // 중앙을 기점으로 시작부터 중간까지 나누기 
         mergeSort(data, middle+1, end); // 중앙을 기점으로 중간부터 끝까지 나누기
         merge(data, start, middle, end); // 정렬된 2개의 배열을 나중에 합쳐줌 
    }
}

int main(void){
    int arr[] = {7, 6, 5, 8, 3, 5, 9, 1};

    mergeSort(arr, 0, number-1);

    for(int i=0;i<number;i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0; 
}