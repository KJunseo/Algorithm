#include<stdio.h>
#include<iostream>
using namespace std;

int main(void){
    int i,j; // 반복을 위한 변수
    int temp; // 두 수의 값을 교환하기 위한 변수
    int array[10] = {1,6,9,8,2,4,10,3,7,5}; // 정렬할 배열

    // 첫 번째 수는 이미 정렬되어있다고 생각하기 때문에, 9까지 반복
    for(i=0;i<9;i++){  
        j=i; // 현재 정렬할 원소를 선택하여 적절한 위치에 삽입하기 위함
        
        // 왼쪽 수가 오른쪽 수보다 크면 자리 교체.(올바른 위치에 삽입)
        while(j>=0 && array[j] > array[j+1]){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            j--;
        }
    }

    for(i=0;i<10;i++){
        cout<<array[i]<<endl;
    }

    return 0; 
}