#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int i,j; // 반복을 위한 변수
    int temp; // 두 수를 교환하기 위한 변수
    int array[10] = {1,6,9,8,2,4,10,3,7,5}; // 정렬할 배열

    for(i=0;i<10;i++){
        for(j=0;j<9-i;j++){
            // 왼 쪽에 있는 수가, 오른쪽에 있는 수보다 크면, 서로 교환 
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for(i=0;i<10;i++){
        cout<<array[i]<<endl;
    }
     
    return 0;
}